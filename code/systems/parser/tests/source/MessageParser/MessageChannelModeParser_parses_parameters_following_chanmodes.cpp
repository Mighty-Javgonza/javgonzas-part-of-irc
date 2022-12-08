#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola");
	parser.lexedMessage.parameters.push_back("+-k");
	parser.lexedMessage.parameters.push_back("adios");
	parser.parse_specific_part();
	if (parser.specific_message->flags[0].parameter != "adios")
		return (-1);
	return (0);
}
