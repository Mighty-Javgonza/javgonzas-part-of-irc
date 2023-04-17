#include "commands.hpp"

static void	reply_with_all_nicks_in_chan(Databasable *database, Client *receiver, Chan *channel, replies_generator *replier)
{
	std::string	all_nicknames = "";
	std::vector<ClientId>	*chan_users = channel->Subscribers();

	for (std::vector<ClientId>::iterator it = chan_users->begin(); it != chan_users->end(); it++)
	{
		Client	*client = database->get_user_from_fd(it->Fd());
		all_nicknames += " " + client->Nick();
	}
	*receiver << replier->names_ok(channel->TypedChanstring(), all_nicknames);
	delete chan_users;
}

static void	reply_with_all_nicks_of_msg_chans(ParsedMessageChannelNames *names_msg, Databasable *database, Client *client, replies_generator *replier)
{
	for (std::vector<channel_parameter>::iterator it = names_msg->channel_list.channels.begin(); it != names_msg->channel_list.channels.end(); it++)
	{
		Chan	*channel = database->get_channel(it->name);
		reply_with_all_nicks_in_chan(database, client, channel, replier);
	}
}

static void	reply_with_all_nicks_of_all_chans(Databasable *database, Client *client, replies_generator *replier)
{
	std::vector<Chan *> all_chans = database->get_all_channels();
	for (std::vector<Chan *>::iterator it = all_chans.begin(); it != all_chans.end(); it++)
	{
		reply_with_all_nicks_in_chan(database, client, *it, replier);
	}
}

void	command_names(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelNames	*names_msg = static_cast<ParsedMessageChannelNames*>(message->message);
	Client	*client = database->get_user_from_fd(message->sender->Fd());
	
	if (names_msg->has_target)
	{
		if (names_msg->target != server_info->hostname)
		{
			*client << replier->names_nosuchserver(names_msg->target);
			return ;
		}
	}
	if (names_msg->channel_list.channels.size() != 0)
		reply_with_all_nicks_of_msg_chans(names_msg, database, client, replier);
	else
		reply_with_all_nicks_of_all_chans(database, client, replier);
}
