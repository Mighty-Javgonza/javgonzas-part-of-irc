#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;
	std::string valid_mode_flags = "OovaimnqpsrtklbeI";

	if (parser.is_valid_mode_flag('x') != false)
		return (-1);

	for (size_t i = 0; i < valid_mode_flags.length(); i++)
		if (parser.is_valid_mode_flag(valid_mode_flags[i]) != true)
			return (-1);

	return (0);
}
