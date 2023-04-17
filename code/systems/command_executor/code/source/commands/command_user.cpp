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
		registering_user->Name(user_msg->user);
		database->register_user(registering_user);
		Client *registered_user = database->get_user_from_fd(message->sender->Fd());
		//TODO: Await for vicmarits imlementation
//		if (user_msg->mode & 0b1000)
//			registered_user->set_invisible_mode();
//		if (user_msg->mode & 0b100)
//			registered_user->set_receive_wallops_mode();
		*registered_user << replier->welcome(registered_user->Nick(), server_info->hostname, server_info->version, "aiwroOs", "oimt", server_info->date, server_info->hostname, server_info->version);
	}
}
