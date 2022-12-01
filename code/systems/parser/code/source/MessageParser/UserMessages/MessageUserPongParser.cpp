#include "MessageUserPongParser.hpp"


MessageUserPongParser::MessageUserPongParser()
{

}

MessageUserPongParser::~MessageUserPongParser()
{

}

void	MessageUserPongParser::parse_specific_part()
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

void	MessageUserPongParser::create_specific_message()
{
	specific_message = new ParsedMessageUserPong();
	in_progress_message = specific_message;
}
