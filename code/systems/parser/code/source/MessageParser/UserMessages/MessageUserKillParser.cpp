#include "MessageUserKillParser.hpp"


MessageUserKillParser::MessageUserKillParser()
{

}

MessageUserKillParser::~MessageUserKillParser()
{

}

void	MessageUserKillParser::parse_specific_part()
{

}

void	MessageUserKillParser::create_specific_message()
{
	specific_message = new ParsedMessageUserKill();
	in_progress_message = specific_message;
}
