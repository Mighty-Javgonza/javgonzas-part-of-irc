#include "commands.hpp"

void	command_user(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionUser	*user_msg = static_cast<ParsedMessageConnectionUser*>(message->message);

	if (database->user_is_registered(message->sender))
	{
		Client*	client = database->get_user_from_fd(message->sender->Fd());

		*client << replier->user_alreadyregistred();
	}
	else
	{
		Unregistered *registering_user = database->get_unregistered_from_fd(message->sender->Fd());
		if (registering_user->__valid_pass == false)
			return ;
		int fd = message->sender->Fd();
		Unregistered *an_attempt_at_poetry_ByVicmarti = database->alter_unregistered_username(registering_user, user_msg->user);
		database->register_user(an_attempt_at_poetry_ByVicmarti);
		Client *registered_user = database->get_user_from_fd(fd);
		if (registered_user == NULL)
			return ;
		if (user_msg->mode & 0b1000)
			registered_user->Mode(ClientData::Invisible, true);
		if (user_msg->mode & 0b100)
			registered_user->Mode(ClientData::Wallops, true);
		*registered_user << replier->welcome(registered_user->Nick(), server_info->hostname, server_info->version, "aiwroOs", "oimt", server_info->date, server_info->hostname, server_info->version);
	}
}
