#include "commands.hpp"

void	command_kick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)database;
	(void)replier;
	(void)server_info;
	ParsedMessageChannelKick	*kick_msg = static_cast<ParsedMessageChannelKick*>(message->message);
}
