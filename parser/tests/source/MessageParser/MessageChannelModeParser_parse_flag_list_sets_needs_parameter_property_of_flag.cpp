#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;
	char	str[3] = "+k";
	str[1] = MODE_FLAGS_WITH_PARAMS[0];

	parser.create_specific_message();
	parser.parse_flag_list(str);
	if (parser.specific_message->flags[0].needs_parameter != true)
		return (-1);
	return (0);
}
