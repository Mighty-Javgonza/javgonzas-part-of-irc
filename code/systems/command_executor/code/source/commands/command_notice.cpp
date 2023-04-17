#include "commands.hpp"

void	command_notice(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessagePrivateMessagesNotice	*notice_msg = static_cast<ParsedMessagePrivateMessagesNotice*>(message->message);

	msgto_parameter	*t;

	for (size_t i = 0; i < notice_msg->target.targets.size(); i++)
	{
		t = &notice_msg->target.targets[i];
		Client *sender = database->get_user_from_fd(message->sender->Fd());
		send_text_message_to_target(sender, notice_msg->message, t, database, "NOTICE", replier);
	}
}
