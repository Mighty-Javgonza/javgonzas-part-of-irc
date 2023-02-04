#include "commands.hpp"

void	command_nick(Databasable *database, SentMessage *message, Replierable *replier)
{
	ParsedMessageConnectionNick	*nick_msg = static_cast<ParsedMessageConnectionNick*>(message->message);

	if (database->nick_is_in_use(nick_msg->nickname))
	{
		(void)replier;
		return ;
	}
	if (database->user_is_registered(message->sender) == false)
		database->register_user(message->sender);
	else
		database->change_nick(message->sender, nick_msg->nickname);
	(void)replier;
}
