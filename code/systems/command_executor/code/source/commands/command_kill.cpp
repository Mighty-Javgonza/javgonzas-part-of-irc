#include "commands.hpp"

void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessageUserKill	*kill_msg = static_cast<ParsedMessageUserKill*>(message->message);
	UserID	user;
	user.nickname = kill_msg->nickname;

	database->kill_user(&user);
	(void)replier; //TODO: reply
}
