#include "MessageChannelInviteParser.hpp"


MessageChannelInviteParser::MessageChannelInviteParser()
{

}

MessageChannelInviteParser::~MessageChannelInviteParser()
{

}

void	MessageChannelInviteParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 2)
		throw (needMoreParamsException);
	specific_message->nickname = lexedMessage.parameters[0];
	MessageParameterValidator::validate_nickname(specific_message->nickname);
	specific_message->channel = MessageParameterCommonParser::parse_channel(lexedMessage.parameters[1]);
}

void	MessageChannelInviteParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelInvite();
	in_progress_message = specific_message;
}
