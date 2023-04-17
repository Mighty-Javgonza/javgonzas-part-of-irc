#include "commands.hpp"

static void	try_to_reply_with_the_channel_topic(Chan *chan, Client *client,replies_generator *replier)
{
	//TODO: Await for vicmarti's implementation
//	if (chan->user_in_chan(client))
//	{
//		if (chan->Mode(Chan::Topic))
//			*client << replier->topic_ok(chan->Name(), chan->topic);
//		else
//			*client << replier->topic_no(chan->Name());
//	}
//	else
		*client << replier->topic_notonchannel(chan->Name());
}

static void	change_channel_topic(Chan *chan, ParsedMessageChannelTopic *topic_msg)
{
	chan->topic = topic_msg->topic;
	//TODO: Await for vicmarti's implementation
//	if (topic_msg->topic == "")
//		chan->Mode(Chan::Topic, false);
}

void	command_topic(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelTopic	*topic_msg = static_cast<ParsedMessageChannelTopic*>(message->message);
	Client	*client = database->get_user_from_fd(message->sender->Fd());
	Chan	*chan = database->get_channel(topic_msg->channel.name);

	//TODO: Await for vicmarti's implementation
//	if (chan->Mode(Chan::Topic) == false)
//	{
//		*client << replier->topic_nochanmodes(chan->Name());
//		return ;
//	}
	if (!topic_msg->has_topic)
		try_to_reply_with_the_channel_topic(chan, client, replier);
	else
	{
		if (chan->IsChop(*client))
			change_channel_topic(chan, topic_msg);
		else
			*client << replier->topic_chanoprivsneeded(chan->Name());
	}
}
