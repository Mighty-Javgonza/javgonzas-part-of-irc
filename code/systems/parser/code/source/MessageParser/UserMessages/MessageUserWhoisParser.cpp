#include "MessageUserWhoisParser.hpp"


MessageUserWhoisParser::MessageUserWhoisParser()
{

}

MessageUserWhoisParser::~MessageUserWhoisParser()
{

}

void	MessageUserWhoisParser::parse_specific_part()
{

}

void	MessageUserWhoisParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWhois();
	in_progress_message = specific_message;
}
