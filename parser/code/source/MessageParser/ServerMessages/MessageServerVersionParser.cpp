#include "MessageServerVersionParser.hpp"


MessageServerVersionParser::MessageServerVersionParser()
{

}

MessageServerVersionParser::~MessageServerVersionParser()
{

}

void	MessageServerVersionParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	}
}

void	MessageServerVersionParser::create_specific_message()
{
	specific_message = new ParsedMessageServerVersion();
	in_progress_message = specific_message;
}
