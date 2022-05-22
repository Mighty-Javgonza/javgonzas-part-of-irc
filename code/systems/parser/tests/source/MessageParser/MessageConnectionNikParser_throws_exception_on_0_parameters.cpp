#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionNickParser	parser;

	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException) {	
		return (0);
	}
	return (-1);
}
