#include "commands.hpp"

void	command_nick(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessageConnectionNick	*nick_msg = static_cast<ParsedMessageConnectionNick*>(message->message);

	if (database->nick_is_in_use(nick_msg->nickname))
	{
		User user = database->get_user_from_fd(message->sender->fd);
		user << replier->nick_nicknameinuse(nick_msg->nickname);
	}
	else
	{
		database->change_nick(message->sender, nick_msg->nickname);
	}
}
