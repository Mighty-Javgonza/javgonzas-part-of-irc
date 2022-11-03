#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageChannelPartParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.parse_specific_part();
	if (parser.specific_message->channel_list.size() != 2)
		return (-1);
	if (parser.specific_message->channel_list.channels[0].name != "hola")
		return (-1);
	return (0);
}
