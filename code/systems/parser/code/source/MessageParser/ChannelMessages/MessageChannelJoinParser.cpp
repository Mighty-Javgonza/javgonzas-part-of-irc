#include "MessageChannelJoinParser.hpp"


MessageChannelJoinParser::MessageChannelJoinParser()
{

}

MessageChannelJoinParser::~MessageChannelJoinParser()
{

}

void	MessageChannelJoinParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	if (lexedMessage.parameters.size() == 1 && lexedMessage.parameters[0] == "0")
		specific_message->leave_all_channels = true;
	else
	{
		specific_message->has_channel_list = true;
		specific_message->channel_list = MessageParameterCommonParser::parse_channel_list(lexedMessage.parameters[0]);
	}
	if (lexedMessage.parameters.size() > 1)
	{
		specific_message->has_key_list = true;
		specific_message->key_list = MessageParameterCommonParser::parse_key_list(lexedMessage.parameters[1]);
	}
}

void	MessageChannelJoinParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelJoin();
	in_progress_message = specific_message;
}
