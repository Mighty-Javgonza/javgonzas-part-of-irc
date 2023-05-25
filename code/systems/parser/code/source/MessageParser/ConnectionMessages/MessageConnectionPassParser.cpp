#include "MessageConnectionPassParser.hpp"


MessageConnectionPassParser::MessageConnectionPassParser()
{

}

MessageConnectionPassParser::~MessageConnectionPassParser()
{

}

void	MessageConnectionPassParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->password = lexedMessage.parameters[0];
}

void	MessageConnectionPassParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionPass();
	in_progress_message = specific_message;
}
