#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionUserParser	parser;

	parser.lexedMessage.parameters.push_back("aaa");
	parser.lexedMessage.parameters.push_back("potato");
	parser.lexedMessage.parameters.push_back("ss");
	parser.lexedMessage.parameters.push_back("Tomas");
	parser.parse_specific_part();
	if (parser.specific_message->mode != 0)
		return (-1);
	return (0);
}
