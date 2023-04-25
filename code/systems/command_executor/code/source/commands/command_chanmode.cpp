#include "commands.hpp"

static void	set_flag(ClientId const &changer, int action, int flag, Chan *channel)
{
	(void)changer;
	(void)action;
	(void)flag;
	(void)channel;
	//TODO: wait for vicmartis implementation
//	if (action == CHANNEL_MODE_FLAG_ACTION_ADD)
//		channel->SetMode(changer, flag);
//	else if (action == CHANNEL_MODE_FLAG_ACTION_REMOVE)
//		channel->UnsetMode(changer, flag);
}

void	command_chanmode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelMode	*chanmode_msg = static_cast<ParsedMessageChannelMode*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());
	Chan	*channel = database->get_channel(chanmode_msg->channel.name);

	if (channel == NULL)
		*client << replier->mode_nosuchchannel(chanmode_msg->channel.name);
	else if (chanmode_msg->flags.size() == 0)
		*client << replier->mode_needmoreparams();
	//TODO: Revisar esta reply
	else if (!channel->IsChop(client->Id()))
	{
		//TODO: Await for vicmartis implementation
	//	*client << replier->mode_chanoprivsneeded(channel->Title());
	}
	else
	{
		ParsedMessageChannelMode::channel_mode_flag	mode_flag = chanmode_msg->flags[0];
		if (mode_flag.flag == 'a')
			set_flag(client->Id(), mode_flag.action, Chan::Anonymous, channel);
		if (mode_flag.flag == 'i')
			set_flag(client->Id(), mode_flag.action, Chan::Invite, channel);
		if (mode_flag.flag == 'q')
			set_flag(client->Id(), mode_flag.action, Chan::Quiet, channel);
		if (mode_flag.flag == 'p')
			set_flag(client->Id(), mode_flag.action, Chan::Private, channel);
		if (mode_flag.flag == 's')
			set_flag(client->Id(),mode_flag.action, Chan::Secret, channel);
		if (mode_flag.flag == 'r')
			set_flag(client->Id(), mode_flag.action, Chan::Reop, channel);
		if (mode_flag.flag == 't')
			set_flag(client->Id(), mode_flag.action, Chan::TopicRestricted, channel);
		if (mode_flag.flag == 'o')
		{
			Client *oper = database->get_user_from_nickname(mode_flag.parameter);

			if (oper == NULL)
				// TODO: Preguntar a vicmarti si el title es el nombre
				*client << replier->mode_usernotinchannel(mode_flag.parameter, channel->Title());
			else
			{
				if (mode_flag.action == CHANNEL_MODE_FLAG_ACTION_ADD)
				{
					if (!channel->IsChop(oper->Id()))
						channel->Chop(client->Id(), oper->Id());
				}
				else
				{
					if (channel->IsChop(oper->Id()))
						channel->Unchop(client->Id(), oper->Id());
				}
			}
		}
	}
}
