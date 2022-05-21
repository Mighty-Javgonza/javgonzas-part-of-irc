#include "MessageParser.hpp"


MessageParser::MessageParser()
{

}

MessageParser::~MessageParser()
{

}

ParsedMessage	*MessageParser::parse(LexedMessage lexed)
{
	(void)lexed;
	return (in_progress_message);
}

void	MessageParser::parse_common_part(void)
{
	in_progress_message->command = lexedMessage.getCommand();
	in_progress_message->preffix = lexedMessage.getPreffix();
}
