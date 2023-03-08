#include "commands.hpp"

static std::string	build_reply(ParsedMessageChannelPart *part_msg, std::string chan_name, std::string user_preffix)
{
	std::string reply;
	if (part_msg->has_part_message)
		reply = ":" + user_preffix + " PART #" + chan_name + " :" + part_msg->part_message + "\r\n";
	else
		reply = ":" + user_preffix + " PART #" + chan_name + " :Has left the channel\r\n";
	return (reply);
}

static void	part_from_chan(Databasable *database, std::string channel_name, ParsedMessageChannelPart *part_msg, User *user, replies_generator *replier)
{
	Channel	*chan = database->get_channel(channel_name);

	if (chan == NULL)
		*user << replier->part_nosuchchannel(channel_name);
	else if (!chan->user_in_chan(user))
		*user << replier->part_notonchannel(*chan);
	else
	{
		chan->user_part(user);

		std::string reply = build_reply(part_msg, chan->name, user->get_preffix_string());
		std::vector<User>	chan_users = chan->get_users();
		send_message_to_user_vector(chan_users, reply);
	}
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
