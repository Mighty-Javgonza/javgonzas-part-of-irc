#include "commands.hpp"

void	command_oper(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageConnectionOper	*oper_msg = static_cast<ParsedMessageConnectionOper*>(message->message);

	User	*user = database->get_user_from_nickname(oper_msg->name);

	if (oper_msg->name == server_info->oper_name)
	{
		if (oper_msg->password == server_info->oper_password)
		{
			if (user->modes.local_operator == false)
			{
				user->modes.local_operator = true;
				*user << replier->oper_ok();
			}
		}
		else
		{
			*user << replier->oper_passwdmismatch();
		}
	}
}
