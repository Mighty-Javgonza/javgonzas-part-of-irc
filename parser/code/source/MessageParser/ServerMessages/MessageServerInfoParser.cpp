#include "MessageServerInfoParser.hpp"


MessageServerInfoParser::MessageServerInfoParser()
{

}

MessageServerInfoParser::~MessageServerInfoParser()
{

}

void	MessageServerInfoParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	}
}

void	MessageServerInfoParser::create_specific_message()
{
	specific_message = new ParsedMessageServerInfo();
	in_progress_message = specific_message;
}
