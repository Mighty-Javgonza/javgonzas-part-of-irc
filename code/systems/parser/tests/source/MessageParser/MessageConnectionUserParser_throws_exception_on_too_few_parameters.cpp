#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionUserParser	parser;

	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException) {	
		parser.lexedMessage.parameters.push_back("aaa");
		parser.lexedMessage.parameters.push_back("aaa");
		parser.lexedMessage.parameters.push_back("aaa");
		try {
			parser.parse_specific_part();
		} catch (MessageParser::NeedMoreParamsException) {	
			return (0);
		}
	}
	return (-1);
}
