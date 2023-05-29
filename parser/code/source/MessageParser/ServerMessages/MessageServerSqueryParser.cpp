#include "MessageServerSqueryParser.hpp"


MessageServerSqueryParser::MessageServerSqueryParser()
{

}

MessageServerSqueryParser::~MessageServerSqueryParser()
{

}

void	MessageServerSqueryParser::parse_specific_part()
{

}

void	MessageServerSqueryParser::create_specific_message()
{
	specific_message = new ParsedMessageServerSquery();
	in_progress_message = specific_message;
}
