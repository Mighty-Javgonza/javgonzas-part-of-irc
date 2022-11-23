#include "MessageUserKillParser.hpp"


MessageUserKillParser::MessageUserKillParser()
{

}

MessageUserKillParser::~MessageUserKillParser()
{

}

void	MessageUserKillParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 2)
		throw (MessageParser::needMoreParamsException);
	MessageParameterValidator::validate_nickname(lexedMessage.parameters[0]);
	specific_message->nickname = lexedMessage.parameters[0];
	specific_message->comment = lexedMessage.parameters[1];
}

void	MessageUserKillParser::create_specific_message()
{
	specific_message = new ParsedMessageUserKill();
	in_progress_message = specific_message;
}
