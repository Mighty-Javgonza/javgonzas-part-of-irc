#include "MessageChannelKickParser.hpp"


MessageChannelKickParser::MessageChannelKickParser()
{

}

MessageChannelKickParser::~MessageChannelKickParser()
{

}

void	MessageChannelKickParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 2)
			throw (MessageParser::needMoreParamsException);
	specific_message->channel_list = MessageParameterCommonParser::parse_channel_list(lexedMessage.parameters[0]);	
	specific_message->user_list = MessageParameterCommonParser::parse_user_list(lexedMessage.parameters[1]);
	if (lexedMessage.parameters.size() > 2)
	{
		specific_message->has_comment = true;
		specific_message->comment = lexedMessage.parameters[2];
	}
}

void	MessageChannelKickParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelKick();
	in_progress_message = specific_message;
}
