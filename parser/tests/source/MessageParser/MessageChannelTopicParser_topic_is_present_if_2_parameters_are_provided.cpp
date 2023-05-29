#include "../tests.hpp"

int main()
{
	LexedMessage						lexedMessage;
	MessageChannelTopicParser	parser;

	parser.lexedMessage.parameters.push_back("#abcd");
	parser.lexedMessage.parameters.push_back("Instructions");
	parser.parse_specific_part();
	if (parser.specific_message->channel.name != "abcd")
		return (-1);
	if (parser.specific_message->has_topic != true)
		return (-1);
	if (parser.specific_message->topic != "Instructions")
		return (-1);
	return (0);
}
