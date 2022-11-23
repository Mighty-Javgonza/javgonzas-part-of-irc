#include "../tests.hpp"

int main()
{
	MessageChannelKickParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.lexedMessage.parameters.push_back("pepe");
	parser.parse_specific_part();
	if (parser.specific_message->channel_list.channels.size() != 2)
		return (-1);
	return (0);
}
