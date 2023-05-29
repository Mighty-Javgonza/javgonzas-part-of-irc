#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola");
	parser.parse_specific_part();
	if (parser.specific_message->channel.name != "hola")
		return (-1);
	return (0);
}
