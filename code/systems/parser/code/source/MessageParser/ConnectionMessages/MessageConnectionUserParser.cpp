#include "MessageConnectionUserParser.hpp"

MessageConnectionUserParser::MessageConnectionUserParser()
{
	create_specific_message();
}

MessageConnectionUserParser::~MessageConnectionUserParser()
{

}

void	MessageConnectionUserParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 4)
		throw (needMoreParamsException);
	specific_message->user = lexedMessage.parameters[0];
	specific_message->mode = std::atoi(lexedMessage.parameters[1].c_str());
	specific_message->unused = lexedMessage.parameters[2];
	specific_message->realname = lexedMessage.parameters[3];
}

void	MessageConnectionUserParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionUser();
	in_progress_message = specific_message;
}
