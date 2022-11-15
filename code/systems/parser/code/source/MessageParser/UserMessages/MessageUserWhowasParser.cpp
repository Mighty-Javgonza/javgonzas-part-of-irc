#include "MessageUserWhowasParser.hpp"


MessageUserWhowasParser::MessageUserWhowasParser()
{

}

MessageUserWhowasParser::~MessageUserWhowasParser()
{

}

void	MessageUserWhowasParser::parse_specific_part()
{

}

void	MessageUserWhowasParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWhowas();
	in_progress_message = specific_message;
}
