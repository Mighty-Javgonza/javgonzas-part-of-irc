#include "commands.hpp"

void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	(void)server_info;
	ParsedMessageUserKill	*kill_msg = static_cast<ParsedMessageUserKill*>(message->message);
	User *user = database->get_user_from_nickname(kill_msg->nickname);
	std::vector<Channel *>user_channels = user->get_channels();
 
	for (std::vector<Channel *>::iterator it = user_channels.begin(); it != user_channels.end(); it++)
	{
		Channel	*channel = database->get_channel((*it)->name);

		part_user_from_chan(user, channel, false, "", database);
	}
	database->kill_user(user);
}
