#include "MessageChannelInviteParser.hpp"


MessageChannelInviteParser::MessageChannelInviteParser()
{

}

MessageChannelInviteParser::~MessageChannelInviteParser()
{

}

void	MessageChannelInviteParser::parse_specific_part()
{

}

void	MessageChannelInviteParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelInvite();
	in_progress_message = specific_message;
}
