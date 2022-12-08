#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	ParsedMessageChannelMode::channel_mode_flag chanflag;
	chanflag.flag = MODE_FLAGS_WITH_NO_PARAMS[0];
	parser.set_needs_parameter(chanflag);
	if (chanflag.needs_parameter != false)
		return (-1);
	chanflag.flag = MODE_FLAGS_WITH_PARAMS[0];
	parser.set_needs_parameter(chanflag);
	if (chanflag.needs_parameter != true)
		return (-1);
	return (0);
}
