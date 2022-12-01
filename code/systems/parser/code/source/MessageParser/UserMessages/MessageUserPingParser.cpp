#include "MessageUserPingParser.hpp"


MessageUserPingParser::MessageUserPingParser()
{

}

MessageUserPingParser::~MessageUserPingParser()
{

}

void	MessageUserPingParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->origin_target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
	if (lexedMessage.parameters.size() > 1)
	{
		specific_message->has_destination_target = true;
		specific_message->destination_target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[1]);
	}
}

void	MessageUserPingParser::create_specific_message()
{
	specific_message = new ParsedMessageUserPing();
	in_progress_message = specific_message;
}
