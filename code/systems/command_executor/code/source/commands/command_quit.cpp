#include "commands.hpp"

static void	relay_quit_to_users_in_shared_channels(Databasable *database, Client *client, ParsedMessageConnectionQuit *quit_msg)
{
	std::vector <ChanId> *user_channels = database->get_all_channels();
	std::string user_preffix = ":" + client->MessagePrefix();
	std::string relay_quit_msg;

	if (quit_msg->has_quit_message)
		relay_quit_msg = user_preffix + " QUIT :" + quit_msg->quit_message + "\r\n";
	else
		relay_quit_msg = user_preffix + " QUIT\r\n";

	for (std::vector<ChanId>::iterator it = user_channels->begin(); it != user_channels->end(); it++)
	{
		Chan	*chan = database->get_channel_from_id(*it);
		std::vector <ClientId> *channel_users = chan->Subscribers();
		for (std::vector<ClientId>::iterator uit = channel_users->begin(); uit != channel_users->end(); uit++)
		{
			Client	*client = database->get_user_from_fd(uit->Fd());
			*client << relay_quit_msg;
		}
		delete channel_users;
	}
	delete user_channels;
}

void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionQuit	*quit_msg = static_cast<ParsedMessageConnectionQuit*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());

	*client << ":" + server_info->get_preffix_string() + " ERROR :Your connection was closed\r\n";
	relay_quit_to_users_in_shared_channels(database, client, quit_msg);
	database->kill_user((ClientId *)&client->Id());
}
