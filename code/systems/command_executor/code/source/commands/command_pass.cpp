#include "commands.hpp"
#include "../../../../vicmarti/src/db/Unregistered.hpp"

static void	set_password_flag(Unregistered *client)
{
	client->ValidatePass();
}

static void	try_accepting_password_for_user(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionPass	*pass_msg = static_cast<ParsedMessageConnectionPass*>(message->message);

	if (database->user_is_registered(message->sender))
	{
		Client *client = database->get_user_from_fd(message->sender->Fd());
		*client << replier->pass_alreadyregistred();
	}
	else
	{
		Unregistered *client = database->get_unregistered_from_fd(message->sender->Fd());
		if (pass_msg->password == server_info->password)
			set_password_flag(client);
	}
}

void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	if (server_info->has_password == false)
		return ;
	else
		try_accepting_password_for_user(database, message, replier, server_info);
}
