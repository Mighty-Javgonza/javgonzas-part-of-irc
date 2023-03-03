#include "commands.hpp"

void	command_user(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessageConnectionUser	*user_msg = static_cast<ParsedMessageConnectionUser*>(message->message);
	User *user = database->get_user_from_fd(message->sender->fd);

	if (database->user_is_registered(message->sender))
	{
		*user << replier->user_alreadyregistred();
	}
	else
	{
		UserID	registration_id;

		registration_id = *message->sender;
		registration_id.user = user_msg->user;
		registration_id.realname = user_msg->realname;
		// TODO registration_id.hostname = ***
		database->register_user(&registration_id);
		if (user_msg->mode & 0b1000)
			database->set_user_invisible_mode(&registration_id);
		if (user_msg->mode & 0b100)
			database->set_user_receive_wallops_mode(&registration_id);
//		TODO **user << replier-> REPLY with welcome
	}
}
