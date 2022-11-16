#include "MessageServerMotdParser.hpp"


MessageServerMotdParser::MessageServerMotdParser()
{

}

MessageServerMotdParser::~MessageServerMotdParser()
{

}

void	MessageServerMotdParser::create_specific_message()
{
	specific_message = new ParsedMessageServerMotd();
	in_progress_message = specific_message;
}

void	MessageServerMotdParser::parse_specific_part()
{

}
