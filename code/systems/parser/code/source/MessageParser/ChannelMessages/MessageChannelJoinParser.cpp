#include "MessageChannelJoinParser.hpp"


MessageChannelJoinParser::MessageChannelJoinParser()
{

}

MessageChannelJoinParser::~MessageChannelJoinParser()
{

}

void	MessageChannelJoinParser::parse_specific_part()
{

}

void	MessageChannelJoinParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelJoin();
	in_progress_message = specific_message;
}
