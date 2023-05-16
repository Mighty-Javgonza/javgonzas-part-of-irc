#include "commands.hpp"

void	command_pong(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;

	Client *client = database->get_user_from_fd(message->sender->Fd());

	client->user_times.reset_t_ping();

}
