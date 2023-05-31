#include "commands.hpp"

void	command_pong(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;

	Client *client = database->get_user_from_fd(message->sender->Fd());

	if (client != NULL)
		client->user_times.reset_t_ping();
	else
	{
		Unregistered *unregistered = database->get_unregistered_from_fd(message->sender->Fd());
		unregistered->user_times.reset_t_ping();
	}


}
