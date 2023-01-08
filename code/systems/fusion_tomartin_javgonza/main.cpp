#include "input_stream_orquestator/LexerParser.hpp"

#include "tomartin/inc/com.hpp"
#include "tomartin/inc/server.hpp"
#include "tomartin/inc/replies.hpp"

void	update_com_server(server &my_server)
{
	my_server.preparation_com();
	my_server.accept_new_connect();
	my_server.orchestation();
}

void	read_received_messages(server &my_server)
{
	std::map<int, user>::iterator	user_it;
	LexerParserConnector	parser;

	user_it = my_server.users.begin();
	while (user_it != my_server.users.end())
	{
		msg	&queue = user_it->second.msg_in;

		if (!queue.check_if_empty())
		{
			std::string	message = queue.extract_msg();

			ParsedMessage *parsed = parser.parse_string(message);

			std::cout << "received command: " << parsed->command << " from user at fd: " << user_it->first << std::endl;
		}
		user_it++;
	}
}

int main()
{
	server	my_server(4242);

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
