#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	parser.parse_flag_list("+k");
	if (parser.specific_message->flags[0].flag != 'k')
		return (-1);
	return (0);
}
