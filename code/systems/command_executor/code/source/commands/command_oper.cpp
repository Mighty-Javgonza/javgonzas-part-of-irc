#include "commands.hpp"

void	command_oper(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionOper	*oper_msg = static_cast<ParsedMessageConnectionOper*>(message->message);

	Client	*client = database->get_user_from_fd(message->sender->Fd());

	if (oper_msg->name == server_info->oper_name)
	{
		if (oper_msg->password == server_info->oper_password)
		{
			if (client->Mode(Client::LocalOperator) == false)
			{
				client->Mode(Client::LocalOperator, true);
				*client << replier->oper_ok();
			}
		}
		else
		{
			*client << replier->oper_passwdmismatch();
		}
	}
}
