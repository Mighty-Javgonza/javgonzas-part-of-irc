#include "../tests.hpp"

int main()
{
	LexedMessage						lexedMessage;
	MessageChannelTopicParser	parser;

	parser.lexedMessage.parameters.push_back("#abcd");
	parser.parse_specific_part();
	if (parser.specific_message->channel.name != "abcd")
		return (-1);
	if (parser.specific_message->has_topic != false)
		return (-1);
	return (0);
}
