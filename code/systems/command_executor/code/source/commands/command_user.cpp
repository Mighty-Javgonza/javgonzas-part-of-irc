#include "commands.hpp"

void	command_user(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessageConnectionUser	*user_msg = static_cast<ParsedMessageConnectionUser*>(message->message);

	(void)database;
	(void)message;
	(void)replier;
	(void)user_msg;
}
