#include "MessagePrivateMessagesNoticeParser.hpp"


MessagePrivateMessagesNoticeParser::MessagePrivateMessagesNoticeParser()
{
	create_specific_message();
}

MessagePrivateMessagesNoticeParser::~MessagePrivateMessagesNoticeParser()
{

}

void	MessagePrivateMessagesNoticeParser::parse_specific_part(void)
{
	if (lexedMessage.parameters.size() < 2)	
		throw (MessageParser::needMoreParamsException);
	specific_message->target = MessageParameterCommonParser::parse_msgtarget(lexedMessage.parameters[0]);
	specific_message->message = lexedMessage.parameters[1];
}

void	MessagePrivateMessagesNoticeParser::create_specific_message(void)
{
	specific_message = new ParsedMessagePrivateMessagesNotice();
}
