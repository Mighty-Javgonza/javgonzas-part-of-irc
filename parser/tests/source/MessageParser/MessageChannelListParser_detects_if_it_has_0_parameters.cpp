#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageChannelListParser	parser;

	parser.create_specific_message();
	parser.parse_specific_part();
	if (parser.specific_message->has_channels != false)
		return (-1);
	return (0);
}
