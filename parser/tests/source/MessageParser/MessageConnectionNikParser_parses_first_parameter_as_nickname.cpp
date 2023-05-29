#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionNickParser	parser;

	parser.lexedMessage.parameters.push_back("abc-123");
	parser.parse_specific_part();
	if (parser.specific_message->nickname != "abc-123")
		return (-1);
	return (0);
}
