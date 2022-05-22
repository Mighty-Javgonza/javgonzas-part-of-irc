#include "MessageConnectionOperParser.hpp"


MessageConnectionOperParser::MessageConnectionOperParser()
{
	create_specific_message();
}

MessageConnectionOperParser::~MessageConnectionOperParser()
{

}

void	MessageConnectionOperParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 2)
		throw (needMoreParamsException);
	specific_message->name = lexedMessage.parameters[0];
	specific_message->password = lexedMessage.parameters[1];
}

void	MessageConnectionOperParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionOper();
	in_progress_message = specific_message;
}
