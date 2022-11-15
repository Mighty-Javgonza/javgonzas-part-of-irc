#include "MessageServerVersionParser.hpp"


MessageServerVersionParser::MessageServerVersionParser()
{

}

MessageServerVersionParser::~MessageServerVersionParser()
{

}

void	MessageServerVersionParser::parse_specific_part()
{

}

void	MessageServerVersionParser::create_specific_message()
{
	specific_message = new ParsedMessageServerVersion();
	in_progress_message = specific_message;
}
