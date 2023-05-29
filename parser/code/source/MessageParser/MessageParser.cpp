#include "MessageParser.hpp"


MessageParser::MessageParser()
{

}

MessageParser::~MessageParser()
{

}

ParsedMessage	*MessageParser::parse(LexedMessage lexed)
{
	lexedMessage = lexed;
	create_specific_message();
	parse_common_part();
	parse_specific_part();
	return (in_progress_message);
}

void	MessageParser::parse_common_part(void)
{
	in_progress_message->command = lexedMessage.getCommand();
	in_progress_message->preffix = lexedMessage.getPreffix();
}
