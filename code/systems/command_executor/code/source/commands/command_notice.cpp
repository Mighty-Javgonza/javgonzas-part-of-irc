#include "commands.hpp"

void	command_notice(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)database;
	(void)replier;
	(void)server_info;
	ParsedMessagePrivateMessagesNotice	*notice_msg = static_cast<ParsedMessagePrivateMessagesNotice*>(message->message);
}
