#include "commands.hpp"

void	kick_user_chan(Databasable *database, User *kicker, User *kickee, Channel *channel, replies_generator *replier, ParsedMessageChannelKick *kick_msg)
{
	if (channel == NULL)
		*kicker << replier->kick_nosuchchannel(*channel);
	else if (!channel->user_in_chan(kicker))
		*kicker << replier->kick_notonchannel(*channel);
	else if (kickee == NULL)
		return ;
		//TODO: await tomartin answer
	//	*kicker << replier->kick_msg_usernotonchannel(*channel);
	else if (!channel->user_in_chan(kickee))
	{
		return ;
		//TODO: await tomartin answer
	//	*kicker << replier->kick_msg_usernotonchannel(*channel);
	}
	else if (!channel->is_operator(kicker))
		*kicker << replier->kick_chanoprivsneeded(*channel);
	else
	{
		std::string	kick_reply = ":" + kicker->get_preffix_string() + " KICK " + " #" + channel->name + " " + kickee->id.nickname;
		if (kick_msg->has_comment)
			kick_reply += " " + kick_msg->comment + "\r\n";
		else
			kick_reply += "\r\n";
		std::vector<User *> chan_users = channel->get_users();
		for (std::vector<User *>::iterator it = chan_users.begin(); it != chan_users.end(); it++)
		{
			//TODO: preguntar a vicmarti por la devolución de usuarios copia
			User *chan_user = database->get_user_from_nickname((*it)->id.nickname);
			*chan_user << kick_reply;
		}
		channel->user_part(kickee);
	}
}

void	command_kick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelKick	*kick_msg = static_cast<ParsedMessageChannelKick*>(message->message);

	User	*kicker = database->get_user_from_fd(message->sender->fd);

	size_t	channel_count = kick_msg->channel_list.channels.size(); 
	size_t	user_count = kick_msg->user_list.users.size();

	if (channel_count != 1 && channel_count != user_count)
	{
		*kicker << replier->kick_needmoreparams("KICK");
	}
	else if (channel_count != 1)
	{
		for (size_t i = 0; i < kick_msg->channel_list.channels.size(); i++)
		{
			User	*kickee = database->get_user_from_nickname(kick_msg->user_list.users[i]);
			Channel	*channel = database->get_channel(kick_msg->channel_list.channels[i].name);
			kick_user_chan(database, kicker, kickee, channel, replier, kick_msg);
		}
	}
	else
	{
		Channel	*channel = database->get_channel(kick_msg->channel_list.channels[0].name);
		for (size_t i = 0; i < kick_msg->user_list.users.size(); i++)
		{
			User	*kickee = database->get_user_from_nickname(kick_msg->user_list.users[i]);
			kick_user_chan(database, kicker, kickee, channel, replier, kick_msg);
		}
	}
	(void)server_info;
}
