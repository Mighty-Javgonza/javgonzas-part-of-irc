#include "commands.hpp"

static void	relay_quit_to_users_in_shared_channels(Databasable *database, Client *client)
{
	std::vector <ChanId> *user_channels = client->Subscriptions();
	std::string user_preffix = ":" + client->MessagePrefix();

	for (std::vector<ChanId>::iterator it = user_channels->begin(); it != user_channels->end(); it++)
	{
		Chan	*chan = database->get_channel_from_id(*it);
		part_user_from_chan(client, client, chan, false, "", database);
	}
	delete user_channels;
}

void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionQuit	*quit_msg = static_cast<ParsedMessageConnectionQuit*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());
	std::string relay_quit_msg;
	if (quit_msg->has_quit_message)
		relay_quit_msg = ":" + client->MessagePrefix() + " QUIT :" + quit_msg->quit_message + "\r\n";
	else
		relay_quit_msg = ":" + client->MessagePrefix() + " QUIT\r\n";
	relay_quit_to_users_in_shared_channels(database, client);
	std::vector<ClientId> *all_users = database->get_all_users();
	for (std::vector<ClientId>::iterator uit = all_users->begin(); uit != all_users->end(); uit++)
	{
		Client	*client = database->get_user_from_fd(uit->Fd());
		*client << relay_quit_msg;
	}
	delete all_users;
	*client << ":" + server_info->get_preffix_string() + " ERROR :Your connection was closed\r\n";
	database->kill_user((ClientId *)&client->Id());
}
