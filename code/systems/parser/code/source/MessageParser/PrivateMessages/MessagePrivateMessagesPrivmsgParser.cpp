#include "MessagePrivateMessagesPrivmsgParser.hpp"


MessagePrivateMessagesPrivmsgParser::MessagePrivateMessagesPrivmsgParser()
{

}

MessagePrivateMessagesPrivmsgParser::~MessagePrivateMessagesPrivmsgParser()
{

}

void	MessagePrivateMessagesPrivmsgParser::parse_specific_part(void)
{
	if (lexedMessage.parameters.size() < 2)	
		throw (MessageParser::needMoreParamsException);
	specific_message->target = MessageParameterCommonParser::parse_msgtarget(lexedMessage.parameters[0]);
	specific_message->message = lexedMessage.parameters[1];
}

void	MessagePrivateMessagesPrivmsgParser::create_specific_message(void)
{
	specific_message = new ParsedMessagePrivateMessagesPrivmsg();
	in_progress_message = specific_message;
}
