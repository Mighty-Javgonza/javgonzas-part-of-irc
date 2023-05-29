#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola");
	parser.lexedMessage.parameters.push_back("+-mov");
	parser.parse_specific_part();
	if (parser.specific_message->flags.size() != 3)
		return (-1);
	return (0);
}
