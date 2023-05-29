#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionOperParser	parser;

	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException) {
		try {
			parser.lexedMessage.parameters.push_back("123");
			parser.parse_specific_part();
		} catch (MessageParser::NeedMoreParamsException) {
			return (0);
		}
	}
	return (-1);
}
