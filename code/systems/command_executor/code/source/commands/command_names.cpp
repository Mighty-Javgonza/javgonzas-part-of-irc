#include "commands.hpp"
#include <set>

static void	reply_with_all_nicks_in_chan(Databasable *database, Client *receiver, Chan *channel, replies_generator *replier, std::set<ClientId> &seenIds)
{
	std::string	all_nicknames = "";
	std::vector<ClientId>	*chan_users = channel->Subscribers();

	if (!chan_users)
		chan_users = new std::vector<ClientId>;
	else
		for (std::vector<ClientId>::iterator it = chan_users->begin(); it != chan_users->end(); it++)
		{
			Client	*client = database->get_user_from_fd(it->Fd());
			if (client == NULL)
				continue ;
			if (channel->IsChop(client->Id()))
				all_nicknames += "@" + client->Nick() + " ";
			else
				all_nicknames += client->Nick() + " ";
			seenIds.insert(*it);
		}
	*receiver << replier->names_ok(channel->TypedChanstring(), all_nicknames);
	delete chan_users;
}

static void	reply_with_all_nicks_of_msg_chans(ParsedMessageChannelNames *names_msg, Databasable *database, Client *client, replies_generator *replier, std::set<ClientId> &seenIds)
{
	for (std::vector<channel_parameter>::iterator it = names_msg->channel_list.channels.begin(); it != names_msg->channel_list.channels.end(); it++)
	{
		Chan	*channel = database->as_outsider_get_channel(client, it->name);
		if (!channel)
			channel = database->get_channel(client, it->name);
		if (!channel)
			*client << replier->join_nosuchchannel(it->name);
		else
			reply_with_all_nicks_in_chan(database, client, channel, replier, seenIds);
	}
}

static void	reply_with_all_nicks_of_all_chans(Databasable *database, Client *client, replies_generator *replier, std::set<ClientId> &seenIds)
{
	std::vector<ChanId> *all_chans = database->get_all_channels();
	for (std::vector<ChanId>::iterator it = all_chans->begin(); it != all_chans->end(); it++)
	{
		Chan *channel = database->as_outsider_get_channel_from_id(client, *it);
		if (!channel)
			channel = database->get_channel_from_id(client, *it);
		if (channel != NULL)
			reply_with_all_nicks_in_chan(database, client, channel, replier, seenIds);
	}
	delete all_chans;
}

void	command_names(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelNames	*names_msg = static_cast<ParsedMessageChannelNames*>(message->message);
	Client	*client = database->get_user_from_fd(message->sender->Fd());
	std::set<ClientId> seenIds;
	
	if (names_msg->has_target)
	{
		if (names_msg->target != server_info->hostname)
		{
			*client << replier->names_nosuchserver(names_msg->target);
			return ;
		}
	}
	if (names_msg->channel_list.channels.size() != 0)
		reply_with_all_nicks_of_msg_chans(names_msg, database, client, replier, seenIds);
	else
	{
		reply_with_all_nicks_of_all_chans(database, client, replier, seenIds);

		std::vector<ClientId>	*all_users = database->get_all_users(client);
		std::string	rogue_users = "";
		for (std::vector<ClientId>::iterator it = all_users->begin(); it != all_users->end(); it++)
		{
			if (seenIds.find(*it) == seenIds.end())
			{
				Client	*client = database->get_user_from_fd(it->Fd());
				rogue_users += client->Nick() + " ";
			}
		}
		if (rogue_users != "")
			*client << replier->names_ok("*", rogue_users);
		*client << replier->names_end("*");
		delete all_users;
	}
}
