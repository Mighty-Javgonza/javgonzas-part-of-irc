#include "commands.hpp"

void	command_invite(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)database;
	(void)replier;
	(void)server_info;
	ParsedMessageChannelInvite	*invite_msg = static_cast<ParsedMessageChannelInvite*>(message->message);
}
