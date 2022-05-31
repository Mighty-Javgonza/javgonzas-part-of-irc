#include "../tests.hpp"

int main()
{
	LexedMessage						lexedMessage;
	MessagePrivateMessagesPrivmsgParser	parser;

	parser.lexedMessage.parameters.push_back("aa");
	parser.lexedMessage.parameters.push_back("buenas tardes, días");
	parser.parse_specific_part();
	if (parser.specific_message->target.targets[0].nickname != "aa")
		return (-1);
	if (parser.specific_message->message != "buenas tardes, días")
		return (-1);
	return (0);
}
