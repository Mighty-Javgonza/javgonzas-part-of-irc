#include "../tests.hpp"

int main()
{
	MessageChannelJoinParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#gogogo");
	parser.parse_specific_part();
	if (parser.specific_message->leave_all_channels != false)
		return (-1);
	if (parser.specific_message->channel_list.channels[0].name != "gogogo")
		return (-1);
	if (parser.specific_message->has_channel_list != true)
		return (-1);
	if (parser.specific_message->has_key_list != false)
		return (-1);
	return (0);
}
