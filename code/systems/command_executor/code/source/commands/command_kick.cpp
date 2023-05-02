#include "commands.hpp"

void	kick_user_chan(Databasable *database, Client *kicker, Client *kickee, Chan *channel, replies_generator *replier, ParsedMessageChannelKick *kick_msg)
{
	if (channel == NULL)
		*kicker << replier->kick_nosuchchannel(channel->Title());
	else if (!channel->IsSubsciptor(kicker->Id()))
		*kicker << replier->kick_notonchannel(channel->Title());
	else if (kickee == NULL)
		*kicker << replier->kick_notonchannel(channel->Title());
	else if (!channel->IsSubsciptor(kickee->Id()))
		*kicker << replier->kick_notonchannel(channel->Title());
	else if (!channel->IsChop(kicker->Id()))
		*kicker << replier->kick_chanoprivsneeded(channel->Title());
	else
	{
		std::string	kick_reply = ":" + kicker->MessagePrefix() + " KICK " + " #" + channel->Title() + " " + kickee->Nick();
		if (kick_msg->has_comment)
			kick_reply += " " + kick_msg->comment + "\r\n";
		else
			kick_reply += "\r\n";
		std::vector<ClientId> *chan_users = channel->Subscribers(kicker->Id());
		for (std::vector<ClientId>::iterator it = chan_users->begin(); it != chan_users->end(); it++)
		{
			Client *chan_user = database->get_user_from_fd(it->Fd());
			*chan_user << kick_reply;
		}
		channel->Leave(kicker->Id(), *kickee);
		delete chan_users;
	}
}

void	command_kick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelKick	*kick_msg = static_cast<ParsedMessageChannelKick*>(message->message);

	Client	*kicker = database->get_user_from_fd(message->sender->Fd());

	size_t	channel_count = kick_msg->channel_list.channels.size(); 
	size_t	user_count = kick_msg->user_list.users.size();

	if (channel_count != 1 && channel_count != user_count)
	{
		*kicker << replier->kick_needmoreparams();
	}
	else if (channel_count != 1)
	{
		for (size_t i = 0; i < kick_msg->channel_list.channels.size(); i++)
		{
			Client	*kickee = database->get_user_from_nickname(kick_msg->user_list.users[i]);
			Chan	*channel = database->get_channel(kick_msg->channel_list.channels[i].name);
			kick_user_chan(database, kicker, kickee, channel, replier, kick_msg);
		}
	}
	else
	{
		Chan	*channel = database->get_channel(kick_msg->channel_list.channels[0].name);
		for (size_t i = 0; i < kick_msg->user_list.users.size(); i++)
		{
			Client	*kickee = database->get_user_from_nickname(kick_msg->user_list.users[i]);
			kick_user_chan(database, kicker, kickee, channel, replier, kick_msg);
		}
	}
	(void)server_info;
}
