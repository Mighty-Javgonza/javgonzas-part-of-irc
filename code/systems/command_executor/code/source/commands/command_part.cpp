#include "commands.hpp"

static std::string	build_reply(Client *client, Chan *chan, bool has_comment, std::string comment)
{
	std::string reply;
	std::string	user_preffix = client->MessagePreffix();
	std::string	chan_name = chan->Name();

	if (has_comment)
		reply = ":" + user_preffix + " PART #" + chan_name + " :" + comment + "\r\n";
	else
		reply = ":" + user_preffix + " PART #" + chan_name + " :Has left the channel\r\n";
	return (reply);
}

void	part_user_from_chan(Client *authority, Client *client, Chan *chan, bool has_comment, std::string comment, Databasable *database)
{
	std::string	reply = build_reply(client, chan, has_comment, comment);

	chan->Leave(authority->Id(), *client);
	send_message_to_users_in_chan(reply, chan, database);
}

void	part_from_chan(Databasable *database, std::string channel_name, ParsedMessageChannelPart *part_msg, Client *client, replies_generator *replier)
{
	Chan	*chan = database->get_channel(channel_name);

	if (chan == NULL)
		*client << replier->part_nosuchchannel(channel_name);
	//TODO: Await for vicmarti's implementation
//	else if (!chan->user_in_chan(client))
//		*client << replier->part_notonchannel(chan->Name());
	else
		part_user_from_chan(client, chan, part_msg->has_part_message, part_msg->part_message, database);
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
