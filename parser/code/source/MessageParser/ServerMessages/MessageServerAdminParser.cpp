#include "MessageServerAdminParser.hpp"


MessageServerAdminParser::MessageServerAdminParser()
{

}

MessageServerAdminParser::~MessageServerAdminParser()
{

}

void	MessageServerAdminParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	}
}

void	MessageServerAdminParser::create_specific_message()
{
	specific_message = new ParsedMessageServerAdmin();
	in_progress_message = specific_message;
}
