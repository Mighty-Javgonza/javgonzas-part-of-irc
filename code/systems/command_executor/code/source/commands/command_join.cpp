#include "commands.hpp"
#include "../../../../database/db/Database.hpp"

static void	part_all_channels(Databasable *database, Client *client) {
	std::vector<ChanId> *sender_channels = client->Subscriptions();
	for (size_t i = 0; i < sender_channels->size(); i++)
	{
		part_user_from_chan(client, client, database->get_channel_from_id((*sender_channels)[i]), false, "", database);
	}
	delete sender_channels;
}

static void	try_join(Databasable *database, Client *client, Chan *chan, replies_generator *replier, std::string const &key = "") {

	(void)key;	
	if (chan->Mode(Chan::InviteOnly) && !chan->IsInvited(*client))
	{
		*client  << replier->invite_chanoprivsneeded(chan->Title());
		return;
	}
//	if (chan->hasLimit() && chan->full()) {
		//TODO reply stuff
		//replier->Error(ERR_CHANNELISFULL, chan);
//		return;
//	}
//	if (chan->hasKey() && !chan->acceptKey(key)) {
		//TODO reply stuff
		//replier->Error(ERR_BADCHANNELKEY, chan);
//		return;
//	}
	if (chan->Mode(Chan::InviteOnly))
		chan->DeleteInvite(client->Nick());
	chan->Join(*client);
	
	std::string	reply = ":" + client->MessagePrefix() + " JOIN " + chan->Title() + "\r\n";
	std::vector<ClientId>	*clients_of_chan = chan->Subscribers();
	for (std::vector<ClientId>::iterator it = clients_of_chan->begin(); it < clients_of_chan->end(); it++)
	{
		Client	*client = database->get_user_from_fd(it->Fd());
		*client << reply;
	}
	delete  clients_of_chan;
}

void	command_join(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info) {
	(void)server_info;
	(void)replier;
	ParsedMessageChannelJoin	*join_msg = static_cast<ParsedMessageChannelJoin*>(message->message);
	Client *sender = database->get_user_from_fd(message->sender->Fd());

	if (join_msg->leave_all_channels) {
		part_all_channels(database, sender);
	} else if (join_msg->has_channel_list) {
		for (size_t i = 0; i < join_msg->channel_list.channels.size(); i++) {
			channel_parameter	chan_param = join_msg->channel_list.channels[i];
			Chan *target_chan = database->get_channel(chan_param.name);
			if (!target_chan)
			{
				database->new_channel(chan_param.name, sender->Id());
				target_chan = database->get_channel(chan_param.name);
			}
			if (join_msg->has_key_list)
				try_join(database, sender, target_chan, replier, join_msg->key_list.keys[i]);
			else
				try_join(database, sender, target_chan, replier);
		}
	}
}

