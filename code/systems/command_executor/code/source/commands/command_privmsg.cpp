#include "commands.hpp"

static void	priv_to_nick(Databasable *database, msgto_parameter *t, std::string sender_preffix, std::string level, std::string message)
{
	User *user = database->get_user_from_nickname(t->nickname);
	if (user != NULL)
		*user << (sender_preffix + " " +  level + " " + t->nickname + " " + message + "\x0d\x0a");
}

static void	priv_to_user_host(Databasable *database, msgto_parameter *t, std::string sender_preffix, std::string level, std::string message)
{
	User *user = database->get_user_from_user_host(t->user, t->host);
	if (user != NULL)
		*user << (sender_preffix + " " + level + " " + t->user + "%" + t->host + " " + message + "\x0d\x0a");
}

static void	priv_to_chan(Databasable *database, msgto_parameter *t, User *sender, std::string sender_preffix, std::string level, std::string message)
{
	std::vector<User *> users = database->get_channel_users(t->channel.name, sender);
	std::string reply_msg = sender_preffix + " " + level + " #" + t->channel.name + " " + message + "\x0d\x0a";
	for (std::vector<User *>::iterator user_it = users.begin(); user_it != users.end(); user_it++)
		**user_it << reply_msg;
}

void	send_text_message_to_target(User *sender, std::string message_str, msgto_parameter *t, Databasable *database, std::string level, replies_generator *replier)
{
	std::string	sender_preffix = sender->get_preffix_string();
	if (t->is_nickname)
		priv_to_nick(database, t, sender_preffix, level, message_str);
	else if (t->is_user)
	{
		if (!t->has_host)
			(void)replier; //TODO reply with identification by servername not implemented
		else
			priv_to_user_host(database, t, sender_preffix, level, message_str);
	}
	else if (t->is_channel)
		priv_to_chan(database, t, sender, sender_preffix, level, message_str);
}

void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessagePrivateMessagesPrivmsg	*privmsg_msg = static_cast<ParsedMessagePrivateMessagesPrivmsg*>(message->message);

	msgto_parameter	*t;

	for (size_t i = 0; i < privmsg_msg->target.targets.size(); i++)
	{
		t = &privmsg_msg->target.targets[i];
		User *sender = database->get_user_from_fd(message->sender->fd);
		send_text_message_to_target(sender, privmsg_msg->message, t, database, "PRIVMSG", replier);
	}
}
