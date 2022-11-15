#include "MessageServerTimeParser.hpp"


MessageServerTimeParser::MessageServerTimeParser()
{

}

MessageServerTimeParser::~MessageServerTimeParser()
{

}

void	MessageServerTimeParser::parse_specific_part()
{

}

void	MessageServerTimeParser::create_specific_message()
{
	specific_message = new ParsedMessageServerTime();
	in_progress_message = specific_message;
}
