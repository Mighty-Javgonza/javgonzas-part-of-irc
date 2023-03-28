#include "commands.hpp"

void	command_invite(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelInvite	*invite_msg = static_cast<ParsedMessageChannelInvite*>(message->message);

	User	*inviter = database->get_user_from_fd(message->sender->fd);
	User	*invitee = database->get_user_from_nickname(invite_msg->nickname);
	std::string	chan_name = invite_msg->channel.name;
	Channel	*channel = database->get_channel(chan_name);

	if (channel == NULL)
	{
		*inviter << replier->invite_notonchannel(chan_name);
	}
	else if (channel->invite_only_flag && !channel->is_operator(inviter))
	{
		//TODO: await tomartin answer
		*inviter << replier->invite_chanoprivsneeded(*channel);
	}
	else if (invitee == NULL)
	{
		//TODO: await tomartin answer
//		*inviter << replier->invite_nosuchnick(invite_msg->nickname);
	}
	else if (channel->user_in_chan(invitee))
	{
		*inviter << replier->invite_useronchannel(*invitee, *channel);
	}
	else if (invitee->modes.away)
	{
		*inviter << replier->invite_away(*invitee);
	}
	else
	{
		//TODO: await tomartin answer
//		inviter << replier->invite_ok(chan, inviter);
		std::string invitation = ":" + inviter->get_preffix_string() + " INVITE " + inviter->id.nickname + " #" + channel->name;
		*invitee << invitation;
	}
}
