#include "MessageServerTimeParser.hpp"


MessageServerTimeParser::MessageServerTimeParser()
{

}

MessageServerTimeParser::~MessageServerTimeParser()
{

}

void	MessageServerTimeParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	}
}

void	MessageServerTimeParser::create_specific_message()
{
	specific_message = new ParsedMessageServerTime();
	in_progress_message = specific_message;
}
