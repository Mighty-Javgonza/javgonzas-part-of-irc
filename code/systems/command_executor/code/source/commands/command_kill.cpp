#include "commands.hpp"

void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;
	ParsedMessageUserKill	*kill_msg = static_cast<ParsedMessageUserKill*>(message->message);
	Client	*killer = database->get_user_from_fd(message->sender->Fd());

	if (!killer->IsOp())
	{
		*killer << replier->kill_noprivileges();
		return ;
	}

	Client *client = database->get_user_from_nickname(kill_msg->nickname);
	if (client == NULL)
		*killer << replier->kill_nosuchnick(kill_msg->nickname);
	std::vector<ChanId> *user_channels = client->Subscriptions();
 
	for (std::vector<ChanId>::iterator it = user_channels->begin(); it != user_channels->end(); it++)
	{
		Chan	*channel = database->get_channel_from_id(*it); 

		channel->Leave(*message->sender, *client);
	}
	database->kill_user((ClientId *)&client->Id());
	delete (user_channels);
}
