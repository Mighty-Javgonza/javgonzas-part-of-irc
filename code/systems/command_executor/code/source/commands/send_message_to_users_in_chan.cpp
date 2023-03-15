#include "commands.hpp"

void	send_message_to_users_in_chan(std::string message, Channel *channel, Databasable *database)
{
	std::vector<User *>	users = channel->get_users();
	for (std::vector<User *>::iterator it = users.begin(); it != users.end(); it++)
	{
		User *user = database->get_user_from_fd((*it)->id.fd);

		*user << message;
	}
}
