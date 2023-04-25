#include "commands.hpp"

void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;
	ParsedMessageUserKill	*kill_msg = static_cast<ParsedMessageUserKill*>(message->message);
	Client *client = database->get_user_from_nickname(kill_msg->nickname);
	std::vector<ChanId> *user_channels = client->Subscriptions();
 
	for (std::vector<ChanId>::iterator it = user_channels->begin(); it != user_channels->end(); it++)
	{
	//TODO: Waiting for vicmarti's implementation
	//	Chan	*channel = database->get_channel(*it); 

//		part_user_from_chan(client, channel, false, "", database);
	}
	database->kill_user(client);
	delete (user_channels);
}