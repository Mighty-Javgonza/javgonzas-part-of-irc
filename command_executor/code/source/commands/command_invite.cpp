#include "commands.hpp"

void	command_invite(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelInvite	*invite_msg = static_cast<ParsedMessageChannelInvite*>(message->message);

	Client	*inviter = database->get_user_from_fd(message->sender->Fd());
	Client	*invitee = database->get_user_from_nickname(inviter, invite_msg->nickname);
	std::string	chan_name = invite_msg->channel.name;
	Chan	*channel = database->get_channel(inviter, chan_name);

	if (channel == NULL)
	{
		*inviter << replier->invite_notonchannel(chan_name);
	}
	else if (channel->Mode(Chan::InviteOnly) && !channel->IsSubscriptor(inviter->Id()))
	{
		*inviter << replier->invite_chanoprivsneeded(channel->Title());
	}
	else if (invitee == NULL)
	{
		*inviter << replier->invite_nosuchnick(invite_msg->nickname);
	}
	else if (channel->IsSubscriptor(invitee->Id()))
	{
		*inviter << replier->invite_useronchannel(invitee->Nick(), channel->Title());
	}
// NOT IMPLEMENTED IN CLIENT
//	else if (invitee->Modes(Away))
//	{
//		*inviter << replier->invite_away(invitee->Nick(), invitee->away_msg);
//	}
	else
	{
		if (!channel->IsInvited(*invitee))
			channel->Invite(invitee->Nick());
		*inviter << replier->invite_ok(channel->Title(), inviter->Nick());
		std::string invitation = ":" + inviter->MessagePrefix() + " INVITE " + inviter->Nick() + " #" + channel->Title() + "\r\n";
		*invitee << invitation;
	}
}
