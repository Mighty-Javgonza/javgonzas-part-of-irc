#include "MessageChannelListParser.hpp"


MessageChannelListParser::MessageChannelListParser()
{

}

MessageChannelListParser::~MessageChannelListParser()
{

}

void	MessageChannelListParser::parse_specific_part()
{

}

void	MessageChannelListParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelList();
	in_progress_message = specific_message;
}
