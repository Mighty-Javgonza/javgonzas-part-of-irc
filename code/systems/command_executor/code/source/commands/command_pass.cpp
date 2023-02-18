#include "commands.hpp"

void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessageConnectionPass	*pass_msg = static_cast<ParsedMessageConnectionPass*>(message->message);

	(void)database;
	(void)message;
	(void)replier;
	(void)pass_msg;
}
