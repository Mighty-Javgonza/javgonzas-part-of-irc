#include "../tests.hpp"

int main()
{
	MessageChannelKickParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.lexedMessage.parameters.push_back("pepe");
	parser.lexedMessage.parameters.push_back("Por tonto!");
	parser.parse_specific_part();
	if (parser.specific_message->has_comment != true)
		return (-1);
	if (parser.specific_message->comment != "Por tonto!")
		return (-1);
	return (0);
}
