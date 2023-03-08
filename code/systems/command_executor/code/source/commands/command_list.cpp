#include "commands.hpp"

void	command_list(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)database;
	(void)replier;
	(void)server_info;
	ParsedMessageChannelList	*list_msg = static_cast<ParsedMessageChannelList*>(message->message);
}
