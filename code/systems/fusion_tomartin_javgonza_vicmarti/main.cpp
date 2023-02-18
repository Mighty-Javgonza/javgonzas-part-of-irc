#include "input_stream_orquestator/LexerParser.hpp"

#include "tomartin/inc/com.hpp"
#include "tomartin/inc/server.hpp"
#include "tomartin/inc/replies.hpp"

#include "vicmarti/src/db/Database.hpp"

#include "input_stream_orquestator/SentMessage.hpp"
#include "input_stream_orquestator/CommandActionAssociator.hpp"

CommandActionAssociator	commandActionAssociator;

void	update_com_server(server &my_server)
{
	my_server.preparation_com();
	my_server.accept_new_connect();
	my_server.orchestation();
}


void	process_first_message_of_user(user &my_user)
{
	LexerParserConnector	parser;
	msg	&queue = my_user.msg_in;
	SentMessage				sentMessage;

	sentMessage.sender = &my_user;
	if (!queue.check_if_empty())
	{
		std::string	message = queue.extract_msg();
		try {
			ParsedMessage *parsed = parser.parse_string(message);
			if (parsed != NULL)
			{
				sentMessage.message = parsed;
				std::cout << "received command: " << parsed->command << std::endl;
			}
			else
			{
				std::cout << "received command: " << parsed->command << std::endl;
			}
		} catch (std::exception &e) {
			std::cout << "received an INVALID command: " << std::endl;
		}

		queue.pop_msg();
	}
}

void	read_received_messages(server &my_server)
{
	std::map<int, user>::iterator	user_it;

	user_it = my_server.users.begin();
	while (user_it != my_server.users.end())
	{
		process_first_message_of_user((*user_it).second);
		user_it++;
	}
}

int main()
{
	server		my_server(4242);
	Database	db;

	try
	{
		while (42)
		{
			update_com_server(my_server);
			read_received_messages(my_server);
		}
	}
	catch (const com_exceptions &e)
	{
		exit(1);
	}
}
