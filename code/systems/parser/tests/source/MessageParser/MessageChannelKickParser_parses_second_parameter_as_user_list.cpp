#include "../tests.hpp"

int main()
{
	MessageChannelKickParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.lexedMessage.parameters.push_back("pepe,tomas");
	parser.parse_specific_part();
	if (parser.specific_message->user_list.users[0] != "pepe")
		return (-1);
	return (0);
}
