#include "MessageServerMotdParser.hpp"


MessageServerMotdParser::MessageServerMotdParser()
{

}

MessageServerMotdParser::~MessageServerMotdParser()
{

}

void	MessageServerMotdParser::create_specific_message()
{
	specific_message = new ParsedMessageServerMotd();
	in_progress_message = specific_message;
}

void	MessageServerMotdParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	}
}
