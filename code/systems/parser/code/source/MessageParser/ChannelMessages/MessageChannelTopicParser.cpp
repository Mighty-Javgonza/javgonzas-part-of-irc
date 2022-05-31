#include "MessageChannelTopicParser.hpp"


MessageChannelTopicParser::MessageChannelTopicParser()
{
	create_specific_message();
}

MessageChannelTopicParser::~MessageChannelTopicParser()
{

}

void	MessageChannelTopicParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->channel = MessageParameterCommonParser::parse_channel(lexedMessage.parameters[0]);
	if (lexedMessage.parameters.size() == 1)
		specific_message->has_topic = false;
	else
	{
		specific_message->has_topic = true;
		specific_message->topic = lexedMessage.parameters[1];
	}
}

void	MessageChannelTopicParser::create_specific_message(void)
{
	specific_message = new ParsedMessageChannelTopic();
	in_progress_message = specific_message;
}
