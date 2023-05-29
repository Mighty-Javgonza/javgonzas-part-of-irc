#include "commands.hpp"

static std::string	build_reply(Client *client, Chan *chan, bool has_comment, std::string comment)
{
	std::string reply;
	std::string	user_preffix = client->MessagePrefix();
	std::string	chan_name = chan->Title();

	if (has_comment)
		reply = ":" + user_preffix + " PART #" + chan_name + " :" + comment + "\r\n";
	else
		reply = ":" + user_preffix + " PART #" + chan_name + " :Has left the channel\r\n";
	return (reply);
}

void	part_user_from_chan(Client *authority, Client *client, Chan *chan, bool has_comment, std::string comment, Databasable *database)
{
	std::string	reply = build_reply(client, chan, has_comment, comment);

	send_message_to_users_in_chan(reply, chan, database);
	database->part(authority->Id(), client->Id(), chan->Id());
}

void	part_from_chan(Databasable *database, std::string channel_name, ParsedMessageChannelPart *part_msg, Client *client, replies_generator *replier)
{
	Chan	*chan = database->get_channel(channel_name);

	if (chan == NULL)
		*client << replier->part_nosuchchannel(channel_name);
	else if (!chan->IsSubscriptor(client->Id()))
		*client << replier->part_notonchannel(chan->Title());
	else
		part_user_from_chan(client, client, chan, part_msg->has_part_message, part_msg->part_message, database);
}	

void	command_part(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelPart	*part_msg = static_cast<ParsedMessageChannelPart*>(message->message);

	Client *client = database->get_user_from_fd(message->sender->Fd());
	
	for (std::vector<channel_parameter>::iterator it = part_msg->channel_list.channels.begin(); it != part_msg->channel_list.channels.end(); it++)
	{
		std::string channel_name = (*it).name;
		part_from_chan(database, channel_name, part_msg, client, replier);
	}
}
