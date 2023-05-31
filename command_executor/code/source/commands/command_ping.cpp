#include "commands.hpp"

void	command_ping(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;

	ClientData *data = database->get_user_from_fd(message->sender->Fd());

	if (!data)
		data = database->get_unregistered_from_fd(message->sender->Fd());
	else
		*data << ":" + server_info->get_preffix_string() + " PONG " + server_info->get_preffix_string() + "\r\n";
}
