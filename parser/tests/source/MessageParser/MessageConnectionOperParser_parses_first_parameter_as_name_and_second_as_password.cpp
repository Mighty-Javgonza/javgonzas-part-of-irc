#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionOperParser	parser;

	parser.lexedMessage.parameters.push_back("abc");
	parser.lexedMessage.parameters.push_back("123");
	parser.parse_specific_part();
	if (parser.specific_message->name != "abc")
		return (-1);
	if (parser.specific_message->password != "123")
		return (-1);
	return (0);
}
