#include "MessageServerInfoParser.hpp"


MessageServerInfoParser::MessageServerInfoParser()
{

}

MessageServerInfoParser::~MessageServerInfoParser()
{

}

void	MessageServerInfoParser::parse_specific_part()
{

}

void	MessageServerInfoParser::create_specific_message()
{
	specific_message = new ParsedMessageServerInfo();
	in_progress_message = specific_message;
}
