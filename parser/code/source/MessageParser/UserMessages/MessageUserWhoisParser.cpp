#include "MessageUserWhoisParser.hpp"


MessageUserWhoisParser::MessageUserWhoisParser()
{

}

MessageUserWhoisParser::~MessageUserWhoisParser()
{

}

void	MessageUserWhoisParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	if (lexedMessage.parameters.size() == 1)
		specific_message->mask_list = MessageParameterCommonParser::parse_mask_list(lexedMessage.parameters[0]);
	if (lexedMessage.parameters.size() > 1)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[0]);
		specific_message->mask_list = MessageParameterCommonParser::parse_mask_list(lexedMessage.parameters[1]);
	}
}

void	MessageUserWhoisParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWhois();
	in_progress_message = specific_message;
}
