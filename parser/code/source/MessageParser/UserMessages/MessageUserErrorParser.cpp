#include "MessageUserErrorParser.hpp"


MessageUserErrorParser::MessageUserErrorParser()
{

}

MessageUserErrorParser::~MessageUserErrorParser()
{

}

void	MessageUserErrorParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (MessageParser::needMoreParamsException);
	specific_message->error_message = lexedMessage.parameters[0];
}

void	MessageUserErrorParser::create_specific_message()
{
	specific_message = new ParsedMessageUserError();
	in_progress_message = specific_message;
}
