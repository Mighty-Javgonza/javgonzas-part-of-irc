#include "commands.hpp"

//This replies' format have not been tested

static void	priv_to_nick(Databasable *database, msgto_parameter *t, std::string sender_preffix, std::string message)
{
	User *user = database->get_user_from_nickname(t->nickname);
	if (user != NULL)
		*user << (sender_preffix + " PRIVMSG " + t->nickname + " " + message + "\x0d\x0a");
}

static void	priv_to_user_host(Databasable *database, msgto_parameter *t, std::string sender_preffix, std::string message)
{
	User *user = database->get_user_from_user_host(t->user, t->host);
	if (user != NULL)
		*user << (sender_preffix + " PRIVMSG " + t->user + "%" + t->host + " " + message + "\x0d\x0a");
}

static void	priv_to_chan(Databasable *database, msgto_parameter *t, User *sender, std::string sender_preffix, std::string message)
{
	std::vector<User *> users = database->get_channel_users(t->channel.name, sender);
	std::string reply_msg = sender_preffix + " PRIVMSG #" + t->channel.name + " " + message + "\x0d\x0a";
	for (std::vector<User *>::iterator user_it = users.begin(); user_it != users.end(); user_it++)
		**user_it << reply_msg;
}

static void	send_privmsg_to_target(User *sender, std::string message_str, msgto_parameter *t, Databasable *database, replies_generator *replier)
{
	std::string	sender_preffix = ":" + sender->id.nickname + "!" + sender->id.user + "@" + sender->id.hostname;
	if (t->is_nickname)
		priv_to_nick(database, t, sender_preffix, message_str);
	else if (t->is_user)
	{
		if (!t->has_host)
			(void)replier; //TODO reply with identification by servername not implemented
		else
			priv_to_user_host(database, t, sender_preffix, message_str);
	}
	else if (t->is_channel)
		priv_to_chan(database, t, sender, sender_preffix, message_str);
}

void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier)
{
	ParsedMessagePrivateMessagesPrivmsg	*privmsg_msg = static_cast<ParsedMessagePrivateMessagesPrivmsg*>(message->message);

	msgto_parameter	*t;

	for (size_t i = 0; i < privmsg_msg->target.targets.size(); i++)
	{
		t = &privmsg_msg->target.targets[i];
		User *sender = database->get_user_from_fd(message->sender->fd);
		send_privmsg_to_target(sender, privmsg_msg->message, t, database, replier);
	}
}
