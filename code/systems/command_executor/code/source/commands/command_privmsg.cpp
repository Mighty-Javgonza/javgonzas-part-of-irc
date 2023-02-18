#include "commands.hpp"

static void	send_privmsg_to_target(msgto_parameter *t, Databasable *database, replies_generator *replier)
{
	///TODO check for existance of user and channels
	if (t->is_nickname)
	{
std::cout << "NICK" << std::endl;
			User user = database->get_user_from_nickname(t->nickname);
			(void)replier; //TODO reply with message to the user
			return ;
	}
	else if (t->is_user)
	{
std::cout << "USER" << std::endl;
		if (!t->has_host)
		{
			(void)replier; //TODO reply with identification by servername not implemented
			return ;
		}
		else
		{
			User user = database->get_user_from_user_host(t->user, t->host);
			(void)replier; //TODO reply with message to the user
			return ;
		}
	}
	else if (t->is_channel)
	{
std::cout << "CHANNEL" << std::endl;
		std::vector<User> users = database->get_channel_users(t->channel.name);
		(void)replier; //TODO reply with message to all users
	}
	(void)replier;
}

void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessagePrivateMessagesPrivmsg	*privmsg_msg = static_cast<ParsedMessagePrivateMessagesPrivmsg*>(message->message);

	msgto_parameter	*t;

std::cout << "size: " << privmsg_msg->target.targets.size() << std::endl;
	for (size_t i = 0; i < privmsg_msg->target.targets.size(); i++)
	{
		t = &privmsg_msg->target.targets[i];
		send_privmsg_to_target(t, database, replier);
	}
}
