#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionPrivmsg	parser;

	parser.lexedMessage.parameters.push_back("");
	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException) {
		return (0);
	}
	return (-1);
}
