#include "commands.hpp"

static void	set_flag(int action, bool *flag)
{
	if (action == CHANNEL_MODE_FLAG_ACTION_ADD)
		*flag = true;
	else if (action == CHANNEL_MODE_FLAG_ACTION_REMOVE)
		*flag = false;
}

void	command_chanmode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;
	ParsedMessageChannelMode	*chanmode_msg = static_cast<ParsedMessageChannelMode*>(message->message);
	User *user = database->get_user_from_fd(message->sender->fd);
	Channel	*channel = database->get_channel(chanmode_msg->channel.name);

	//TODO: change to mode_nosuchchannel
	if (channel == NULL)
		*user << replier->part_nosuchchannel(chanmode_msg->channel.name);
	//TODO: change to mode_needmoreparams
	else if (chanmode_msg->flags.size() == 0)
		*user << replier->topic_needmoreparams("MODE");
	//TODO: Revisar esta reply
	else if (!channel->is_operator(user))
		*user << replier->mode_chanoprivsneeded(channel->name);
	else
	{
		ParsedMessageChannelMode::channel_mode_flag	mode_flag = chanmode_msg->flags[0];
		if (mode_flag.flag == 'a')
			set_flag(mode_flag.action, &channel->anonymous_flag);
		if (mode_flag.flag == 'i')
			set_flag(mode_flag.action, &channel->invite_only_flag);
		if (mode_flag.flag == 'q')
			set_flag(mode_flag.action, &channel->quiet_flag);
		if (mode_flag.flag == 'p')
			set_flag(mode_flag.action, &channel->private_flag);
		if (mode_flag.flag == 's')
			set_flag(mode_flag.action, &channel->secret_flag);
		if (mode_flag.flag == 'r')
			set_flag(mode_flag.action, &channel->reop_flag);
		if (mode_flag.flag == 't')
			set_flag(mode_flag.action, &channel->topic_flag);
		if (mode_flag.flag == 'o')
		{
			User *oper = database->get_user_from_nickname(mode_flag.parameter);

			//TODO change to mode_usernotonchannel
			if (oper == NULL)
				*user << replier->invite_useronchannel(*oper, *channel);
			else
				channel->make_operator(oper);
		}
	}
}
