#include "MessageUserPongParser.hpp"


MessageUserPongParser::MessageUserPongParser()
{

}

MessageUserPongParser::~MessageUserPongParser()
{

}

void	MessageUserPongParser::parse_specific_part()
{

}

void	MessageUserPongParser::create_specific_message()
{
	specific_message = new ParsedMessageUserPong();
	in_progress_message = specific_message;
}
