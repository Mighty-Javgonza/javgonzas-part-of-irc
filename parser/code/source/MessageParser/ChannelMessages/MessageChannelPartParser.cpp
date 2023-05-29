#include "MessageChannelPartParser.hpp"


MessageChannelPartParser::MessageChannelPartParser()
{

}

MessageChannelPartParser::~MessageChannelPartParser()
{

}
void    MessageChannelPartParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->channel_list = MessageParameterCommonParser::parse_channel_list(lexedMessage.parameters[0]);

	if (lexedMessage.parameters.size() > 1)
	{
		specific_message->has_part_message = true;
		specific_message->part_message = lexedMessage.parameters[1];
	}
}

void    MessageChannelPartParser::create_specific_message(void)
{
    specific_message = new ParsedMessageChannelPart();
    in_progress_message = specific_message;
}
