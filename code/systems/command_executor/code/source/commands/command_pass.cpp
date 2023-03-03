#include "commands.hpp"

static void	set_password_flag(User *user, ParsedMessageConnectionPass *pass_msg, ServerInfo *server_info)
{
	if (pass_msg->password == server_info->password)
		user->register_pass_correct = true;
	else
		user->register_pass_correct = false;
}

static void	try_accepting_password_for_user(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionPass	*pass_msg = static_cast<ParsedMessageConnectionPass*>(message->message);

	User *user = database->get_user_from_fd(message->sender->fd);

	if (database->user_is_registered(message->sender))
		*user << replier->pass_alreadyregistred();
	else
		set_password_flag(user, pass_msg, server_info);
}

void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	if (server_info->has_password == false)
		return ;
	else
		try_accepting_password_for_user(database, message, replier, server_info);
}
