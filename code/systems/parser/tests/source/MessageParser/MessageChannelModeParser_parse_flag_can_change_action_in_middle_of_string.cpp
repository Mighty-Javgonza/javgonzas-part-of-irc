#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	parser.parse_flag_list("-k+r");
	if (parser.specific_message->flags[1].action != CHANNEL_MODE_FLAG_ACTION_ADD)
		return (-1);
	return (0);
}
