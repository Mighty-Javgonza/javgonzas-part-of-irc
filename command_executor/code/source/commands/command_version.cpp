#include "commands.hpp"

void	command_version(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageServerVersion	*version_msg = static_cast<ParsedMessageServerVersion*>(message->message);

	Client *client = database->get_user_from_fd(message->sender->Fd());

	if (version_msg->has_target && !version_msg->target.is_servername)
		*client << replier->version_nosuchserver(version_msg->target.nickname);
	else if ((version_msg->has_target == true) && (version_msg->target.servername != server_info->hostname))
		*client << replier->version_nosuchserver(version_msg->target.servername);
	else
		*client << replier->version_ok(server_info->version, server_info->debug_lvl, server_info->hostname, server_info->comment);
}
