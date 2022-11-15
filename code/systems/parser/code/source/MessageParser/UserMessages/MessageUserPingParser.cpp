#include "MessageUserPingParser.hpp"


MessageUserPingParser::MessageUserPingParser()
{

}

MessageUserPingParser::~MessageUserPingParser()
{

}

void	MessageUserPingParser::parse_specific_part()
{

}

void	MessageUserPingParser::create_specific_message()
{
	specific_message = new ParsedMessageUserPing();
	in_progress_message = specific_message;
}
