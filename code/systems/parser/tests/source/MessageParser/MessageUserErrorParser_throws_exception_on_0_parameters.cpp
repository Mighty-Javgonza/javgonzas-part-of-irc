#include "../tests.hpp"

int main()
{
	MessageUserErrorParser	parser;

	parser.create_specific_message();
	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException &e) {
		parser.lexedMessage.parameters.push_back("HOIHOI");
		parser.parse_specific_part();
		return (0);
	}
	return (-1);
}
