#include "MessageUserWhoParser.hpp"


MessageUserWhoParser::MessageUserWhoParser()
{

}

MessageUserWhoParser::~MessageUserWhoParser()
{

}

void	MessageUserWhoParser::parse_specific_part()
{

}

void	MessageUserWhoParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWho();
	in_progress_message = specific_message;
}
