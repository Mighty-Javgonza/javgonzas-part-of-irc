#include "MessageConnectionNickParser.hpp"
#include "../MessageParameterValidator.hpp"


MessageConnectionNickParser::MessageConnectionNickParser()
{
	create_specific_message();
}

MessageConnectionNickParser::~MessageConnectionNickParser()
{

}

void	MessageConnectionNickParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	MessageParameterValidator::validate_nickname(lexedMessage.parameters[0]);
	specific_message->nickname = lexedMessage.parameters[0];
}

void	MessageConnectionNickParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionNick();
	in_progress_message = specific_message;
}
