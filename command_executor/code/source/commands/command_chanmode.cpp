#include "commands.hpp"

static void	set_flag(Client const *changer, ParsedMessageChannelMode::channel_mode_flag cflag, enum Chan::Mode flag, Chan *channel, char letter, Databasable *database)
{
	std::string relay_message;

	if (cflag.action == CHANNEL_MODE_FLAG_ACTION_ADD)
	{
		if (cflag.needs_parameter)
			relay_message = ":" + changer->MessagePrefix() + " MODE +" + letter + " " + cflag.parameter + "\r\n";
		else
			relay_message = ":" + changer->MessagePrefix() + " MODE +" + letter + "\r\n";
		channel->Mode(changer->Id(), flag, true);
	}
	else if (cflag.action == CHANNEL_MODE_FLAG_ACTION_REMOVE)
	{
		if (cflag.needs_parameter)
			relay_message = ":" + changer->MessagePrefix() + " MODE " + channel->Title() + " -" + letter + " " + cflag.parameter + "\r\n";
		else
			relay_message = ":" + changer->MessagePrefix() + " MODE " + channel->Title() + "-" + letter + "\r\n";
		channel->Mode(changer->Id(), flag, false);
	}
	send_message_to_users_in_chan(relay_message, channel, database);
}

void	command_chanmode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageChannelMode	*chanmode_msg = static_cast<ParsedMessageChannelMode*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());
	Chan	*channel = database->get_channel(client, chanmode_msg->channel.name);

	if (channel == NULL)
		*client << replier->mode_nosuchchannel(chanmode_msg->channel.name);
	else if (chanmode_msg->flags.size() == 0)
		*client << replier->mode_channelmodeis(channel->Title(), channel->ModeString(), "");
	else if (!channel->IsChop(client->Id()))
		*client << replier->mode_chanoprivsneeded(channel->Title());
	else
	{
		ParsedMessageChannelMode::channel_mode_flag	mode_flag = chanmode_msg->flags[0];
		if (mode_flag.flag == 'a')
			set_flag(client, mode_flag, Chan::Anonymous, channel, 'a', database);
		if (mode_flag.flag == 'i')
		{
			set_flag(client, mode_flag, Chan::InviteOnly, channel, 'i', database);
			if (mode_flag.action == CHANNEL_MODE_FLAG_ACTION_ADD)
				channel->ClearInvites();
		}
		if (mode_flag.flag == 'q')
			set_flag(client, mode_flag, Chan::Quiet, channel, 'q', database);
		if (mode_flag.flag == 'p')
			set_flag(client, mode_flag, Chan::Private, channel, 'p', database);
		if (mode_flag.flag == 's')
			set_flag(client, mode_flag, Chan::Secret, channel, 's', database);
		if (mode_flag.flag == 'r')
			set_flag(client, mode_flag, Chan::Reop, channel, 'r', database);
		if (mode_flag.flag == 't')
			set_flag(client, mode_flag, Chan::TopicRestricted, channel, 't', database);
		if (mode_flag.flag == 'l')
		{
			if (mode_flag.action == CHANNEL_MODE_FLAG_ACTION_ADD)
			{
				int	limit = std::stoi(mode_flag.parameter);
				channel->LimitMaxSubs(client->Id(), limit);
			}
			set_flag(client, mode_flag, Chan::Limited, channel, 'l', database);
		}
		if (mode_flag.flag == 'o')
		{
			Client *oper = database->get_user_from_nickname(client, mode_flag.parameter);
std::cout << "oper parameter is:" << mode_flag.parameter << std::endl;

			if (oper == NULL)
				*client << replier->mode_usernotinchannel(mode_flag.parameter, channel->Title());
			else
			{
				if (mode_flag.action == CHANNEL_MODE_FLAG_ACTION_ADD)
				{
					if (!channel->IsChop(oper->Id()))
					{
						send_message_to_users_in_chan(":" + server_info->get_preffix_string() + " WALLOPS :" + oper->Nick() + " has been made an operator of #" + channel->Title() + " by " + client->Nick() + "\r\n", channel, database);
						channel->Chop(client->Id(), oper->Id());
					}
				}
				else
				{
					if (channel->IsChop(oper->Id()))
					{
						send_message_to_users_in_chan(":" + server_info->get_preffix_string() + " WALLOPS :" + client->Nick() + " has revoked the Chanop permissions of " + oper->Nick() + " in #" + channel->Title() + "\r\n", channel, database );
						channel->Unchop(client->Id(), oper->Id());
					}
				}
			}
		}
	}
}
