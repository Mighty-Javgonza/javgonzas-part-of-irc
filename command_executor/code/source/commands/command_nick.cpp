#include "commands.hpp"

void	command_nick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageConnectionNick	*nick_msg = static_cast<ParsedMessageConnectionNick*>(message->message);

	if (database->nick_is_in_use(nick_msg->nickname))
	{
		ClientData* client = database->get_client_data_from_fd(message->sender->Fd());
		*client << replier->nick_nicknameinuse(nick_msg->nickname);
	}
	else
	{
		database->change_nick(message->sender, nick_msg->nickname);
	}
}
