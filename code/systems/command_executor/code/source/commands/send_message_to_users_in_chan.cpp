#include "commands.hpp"

void	send_message_to_users_in_chan(std::string message, Chan *channel, Databasable *database)
{
	std::vector<ClientId>	*clients = channel->Subscribers();
	for (std::vector<ClientId>::iterator it = clients->begin(); it != clients->end(); it++)
	{
		Client *client = database->get_user_from_fd(it->Fd());

		if (client != NULL)
			*client << message;
	}
	delete clients;
}
