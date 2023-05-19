#include "commands.hpp"

void	mixed_command_mode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelMode	*chanmode_msg = dynamic_cast<ParsedMessageChannelMode*>(message->message);

	if (chanmode_msg == NULL)
		command_mode(database, message, replier, server_info);
	else
		command_chanmode(database, message, replier, server_info);
}
