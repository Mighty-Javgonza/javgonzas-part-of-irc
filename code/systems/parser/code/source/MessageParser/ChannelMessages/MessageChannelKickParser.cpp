#include "MessageChannelKickParser.hpp"


MessageChannelKickParser::MessageChannelKickParser()
{

}

MessageChannelKickParser::~MessageChannelKickParser()
{

}

void	MessageChannelKickParser::parse_specific_part()
{

}

void	MessageChannelKickParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelKick();
	in_progress_message = specific_message;
}
