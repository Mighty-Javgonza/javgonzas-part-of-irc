#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionUserParser	parser;

	parser.lexedMessage.parameters.push_back("aaa");
	parser.lexedMessage.parameters.push_back("11");
	parser.lexedMessage.parameters.push_back("ss");
	parser.lexedMessage.parameters.push_back("Tomas");
	parser.parse_specific_part();
	if (parser.specific_message->user != "aaa")
		return (-1);
	if (parser.specific_message->mode != 11)
		return (-1);
	if (parser.specific_message->unused != "ss")
		return (-1);
	if (parser.specific_message->realname != "Tomas")
		return (-1);
	return (0);
}
