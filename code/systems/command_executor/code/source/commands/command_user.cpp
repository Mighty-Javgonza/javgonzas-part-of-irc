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
		int fd = message->sender->Fd();
		Unregistered *an_attempt_at_poetry_ByVicmarti = database->alter_unregistered_username(registering_user, user_msg->user);
//		if (!an_attempt_at_poetry_ByVicmarti->IsReady())
//		{
//			if (server_info->has_password)
//				*an_attempt_at_poetry_ByVicmarti << ":" + server_info->get_preffix_string() + " ERROR :Either password is invalid or nick is not set\r\n";
//			else
//				*an_attempt_at_poetry_ByVicmarti << ":" + server_info->get_preffix_string() + " ERROR :Nick is not set\r\n";
//			return;
//		}


//		registering_user->Id().User(user_msg->user);
		database->register_user(an_attempt_at_poetry_ByVicmarti);
		Client *registered_user = database->get_user_from_fd(fd);
		if (user_msg->mode & 0b1000)
			registered_user->Mode(ClientData::Invisible, true);
		if (user_msg->mode & 0b100)
			registered_user->Mode(ClientData::Wallops, true);
		*registered_user << replier->welcome(registered_user->Nick(), server_info->hostname, server_info->version, "aiwroOs", "oimt", server_info->date, server_info->hostname, server_info->version);
	}
}
