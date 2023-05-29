#include "commands.hpp"

void	command_motd(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageServerMotd	*motd_msg = static_cast<ParsedMessageServerMotd*>(message->message);

	Client *client = database->get_user_from_fd(message->sender->Fd());
	if (motd_msg->has_target && !motd_msg->target.is_servername)
		*client << replier->version_nosuchserver(motd_msg->target.nickname);
	else if (!motd_msg->has_target || (motd_msg->has_target && (motd_msg->target.servername == server_info->hostname)))
	{
		if(server_info->motd == "")
			*client << replier->motd_nomotd();
		else
			*client << replier->motd_ok(server_info->hostname, server_info->motd);
	}
	else
		*client << replier->motd_nomotd();
}
