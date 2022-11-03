#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageChannelNamesParser	parser;

	parser.create_specific_message();
	parser.parse_specific_part();
	return (0);
}
