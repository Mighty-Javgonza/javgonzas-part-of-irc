#include "MessageServerStatsParser.hpp"


MessageServerStatsParser::MessageServerStatsParser()
{

}

MessageServerStatsParser::~MessageServerStatsParser()
{

}

void	MessageServerStatsParser::parse_specific_part()
{

}

void	MessageServerStatsParser::create_specific_message()
{
	specific_message = new ParsedMessageServerStats();
	in_progress_message = specific_message;
}
