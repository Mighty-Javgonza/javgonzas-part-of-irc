#include "commands.hpp"

void	command_user(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionUser	*user_msg = static_cast<ParsedMessageConnectionUser*>(message->message);
	User *registering_user = database->get_user_from_fd(message->sender->fd);

	if (database->user_is_registered(message->sender))
	{
		*registering_user << replier->user_alreadyregistred();
	}
	else
	{
		registering_user->set_username(user_msg->user);
		registering_user->set_realname(user_msg->user);
		registering_user->set_hostname(message->sender->hostname);
		database->register_user(registering_user);
		User *registered_user = database->get_user_from_fd(message->sender->fd);
		if (user_msg->mode & 0b1000)
			registered_user->set_invisible_mode();
		if (user_msg->mode & 0b100)
			registered_user->set_receive_wallops_mode();
		*registered_user << replier->welcome(registered_user->id.nickname, server_info->hostname, server_info->version, "aiwroOs", "oimt", server_info->date, server_info->hostname, server_info->version);
	}
}
