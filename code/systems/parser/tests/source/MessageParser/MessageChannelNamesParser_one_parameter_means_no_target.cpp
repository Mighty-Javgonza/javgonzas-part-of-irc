#include "../tests.hpp"

int main()
{

	LexedMessage				lexedMessage;
	MessageChannelNamesParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#abcd");
	parser.parse_specific_part();
	if (parser.specific_message->has_target != false)
		return (-1);
	return (0);
}
