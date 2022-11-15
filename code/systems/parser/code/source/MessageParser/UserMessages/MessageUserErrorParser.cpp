#include "MessageUserErrorParser.hpp"


MessageUserErrorParser::MessageUserErrorParser()
{

}

MessageUserErrorParser::~MessageUserErrorParser()
{

}

void	MessageUserErrorParser::parse_specific_part()
{

}

void	MessageUserErrorParser::create_specific_message()
{
	specific_message = new ParsedMessageUserError();
	in_progress_message = specific_message;
}
