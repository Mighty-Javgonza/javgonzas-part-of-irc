#include "../tests.hpp"

int main()
{

	LexedMessage				lexedMessage;
	MessageChannelNamesParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#abcd");
	parser.lexedMessage.parameters.push_back("127.0.0.1");
	parser.parse_specific_part();
	if (parser.specific_message->has_target != true)
		return (-1);
	if (parser.specific_message->target != "127.0.0.1")
		return (-1);
	return (0);
}
