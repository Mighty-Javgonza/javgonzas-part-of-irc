#include "commands.hpp"

void	command_ping(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;

	Client *client = database->get_user_from_fd(message->sender->Fd());

	*client << ":" + server_info->get_preffix_string() + " PONG " + server_info->get_preffix_string() + "\r\n";
}
