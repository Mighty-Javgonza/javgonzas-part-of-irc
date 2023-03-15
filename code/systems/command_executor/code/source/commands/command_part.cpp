#include "commands.hpp"

static std::string	build_reply(User *user, Channel *chan, bool has_comment, std::string comment)
{
	std::string reply;
	std::string	user_preffix = user->get_preffix_string();
	std::string	chan_name = chan->name;

	if (has_comment)
		reply = ":" + user_preffix + " PART #" + chan_name + " :" + comment + "\r\n";
	else
		reply = ":" + user_preffix + " PART #" + chan_name + " :Has left the channel\r\n";
	return (reply);
}

//Unprotected funcion, make sure you are sure everything is ok before calling
void	part_user_from_chan(User *user, Channel *chan, bool has_comment, std::string comment, Databasable *database)
{
	std::string	reply = build_reply(user, chan, has_comment, comment);

	chan->user_part(user);
	send_message_to_users_in_chan(reply, chan, database);
}

void	part_from_chan(Databasable *database, std::string channel_name, ParsedMessageChannelPart *part_msg, User *user, replies_generator *replier)
{
	Channel	*chan = database->get_channel(channel_name);

	if (chan == NULL)
		*user << replier->part_nosuchchannel(channel_name);
	else if (!chan->user_in_chan(user))
		*user << replier->part_notonchannel(*chan);
	else
		part_user_from_chan(user, chan, part_msg->has_part_message, part_msg->part_message, database);
}	
void	command_part(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelPart	*part_msg = static_cast<ParsedMessageChannelPart*>(message->message);

	User *user = database->get_user_from_fd(message->sender->fd);

	
	for (std::vector<channel_parameter>::iterator it = part_msg->channel_list.channels.begin(); it != part_msg->channel_list.channels.end(); it++)
	{
		std::string channel_name = (*it).name;
		part_from_chan(database, channel_name, part_msg, user, replier);
	}
}
