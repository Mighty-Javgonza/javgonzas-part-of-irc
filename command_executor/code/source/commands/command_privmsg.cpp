#include "commands.hpp"

static void	priv_to_nick(Databasable *database, msgto_parameter *t, Client *sender, std::string level, std::string message, replies_generator &rp)
{
	Client *client = database->get_user_from_nickname(sender, t->nickname);
	if (client != NULL)
		*client << (":" + sender->MessagePrefix() + " " +  level + " " + t->nickname + " :" + message + "\x0d\x0a");
	else
		*sender << rp.privmsg_nosuchnick(t->nickname);
}

static void	priv_to_user_host(Databasable *database, msgto_parameter *t, Client *sender, std::string level, std::string message)
{
	Client *client = database->get_user_from_user_host(sender, t->user, t->host);
	if (client != NULL)
		*client << (":" + sender->MessagePrefix() + " " + level + " " + t->user + "%" + t->host + " :" + message + "\x0d\x0a");
}

static void	priv_to_chan(Databasable *database, msgto_parameter *t, Client *sender, std::string level, std::string message, replies_generator *replier)
{
	Chan	*chan = database->get_channel(sender, t->channel.name);
	if (!chan)
	{
		*sender << replier->privmsg_cannotsendtochan(t->channel.name);
		return ;
	}
	std::vector<ClientId> *clients = chan->Subscribers();
	std::string reply_msg = ":" + sender->MessagePrefix() + " " + level + " #" + t->channel.name + " :" + message + "\x0d\x0a";

	for (std::vector<ClientId>::iterator client_it = clients->begin(); client_it != clients->end(); client_it++)
	{
		Client *client = database->get_user_from_fd(client_it->Fd());
		*client << reply_msg;
	}
	delete clients;
}

void	send_text_message_to_target(Client *sender, std::string message_str, msgto_parameter *t, Databasable *database, std::string level, replies_generator *replier)
{
	if (t->is_nickname)
		priv_to_nick(database, t, sender, level, message_str, *replier);
	else if (t->is_user)
	{
		if (!t->has_host)
			(void)replier; //TODO reply with identification by servername not implemented
		else
			priv_to_user_host(database, t, sender, level, message_str);
	}
	else if (t->is_channel)
		priv_to_chan(database, t, sender, level, message_str, replier);
}

void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessagePrivateMessagesPrivmsg	*privmsg_msg = static_cast<ParsedMessagePrivateMessagesPrivmsg*>(message->message);

	msgto_parameter	*t;

	for (size_t i = 0; i < privmsg_msg->target.targets.size(); i++)
	{
		t = &privmsg_msg->target.targets[i];
		Client *sender = database->get_user_from_fd(message->sender->Fd());
		send_text_message_to_target(sender, privmsg_msg->message, t, database, "PRIVMSG", replier);
	}
}