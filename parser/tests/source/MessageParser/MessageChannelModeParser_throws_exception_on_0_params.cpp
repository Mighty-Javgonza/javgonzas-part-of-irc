#include "../tests.hpp"

int main()
{
	MessageChannelModeParser	parser;

	parser.create_specific_message();
	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException &e) {
		return (0);
	}
	return (-1);
}
