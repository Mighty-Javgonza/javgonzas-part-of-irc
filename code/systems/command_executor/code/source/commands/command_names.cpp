#include "commands.hpp"

static void	reply_with_all_nicks_in_chan(User *receiver, Channel *channel, replies_generator *replier)
{
	std::string	all_nicknames = "";
	std::vector<User *>	chan_users = channel->get_users();

	for (std::vector<User *>::iterator it = chan_users.begin(); it != chan_users.end(); it++)
		all_nicknames += " " + (*it)->id.nickname;
	*receiver << replier->names_ok(channel->get_typed_channel_string(), all_nicknames);
}

static void	reply_with_all_nicks_of_msg_chans(ParsedMessageChannelNames *names_msg, Databasable *database, User *user, replies_generator *replier)
{
	for (std::vector<channel_parameter>::iterator it = names_msg->channel_list.channels.begin(); it != names_msg->channel_list.channels.end(); it++)
	{
		Channel	*channel = database->get_channel(it->name);
		reply_with_all_nicks_in_chan(user, channel, replier);
	}
}

static void	reply_with_all_nicks_of_all_chans(Databasable *database, User *user, replies_generator *replier)
{
	std::vector<Channel *> all_chans = database->get_all_channels();
	for (std::vector<Channel *>::iterator it = all_chans.begin(); it != all_chans.end(); it++)
	{
		reply_with_all_nicks_in_chan(user, *it, replier);
	}
}

void	command_names(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelNames	*names_msg = static_cast<ParsedMessageChannelNames*>(message->message);
	User	*user = database->get_user_from_fd(message->sender->fd);
	
	if (names_msg->has_target)
	{
		if (names_msg->target != server_info->hostname)
		{
			*user << replier->names_nosuchserver(names_msg->target);
			return ;
		}
	}
	if (names_msg->channel_list.channels.size() != 0)
		reply_with_all_nicks_of_msg_chans(names_msg, database, user, replier);
	else
		reply_with_all_nicks_of_all_chans(database, user, replier);
}
