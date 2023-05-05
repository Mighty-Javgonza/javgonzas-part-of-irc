#include "commands.hpp"

static void	try_to_reply_with_the_channel_topic(Chan *chan, Client *client,replies_generator *replier)
{
	if (chan->IsSubscriptor(client->Id()))
	{
		if (chan->Topic() != "")
			*client << replier->topic_ok(chan->Title(), chan->Topic());
		else
			*client << replier->topic_no(chan->Title());
	}
	else
		*client << replier->topic_notonchannel(chan->Title());
}

void	command_topic(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelTopic	*topic_msg = static_cast<ParsedMessageChannelTopic*>(message->message);
	Client	*client = database->get_user_from_fd(message->sender->Fd());
	Chan	*chan = database->get_channel(topic_msg->channel.name);

	if (!topic_msg->has_topic)
		try_to_reply_with_the_channel_topic(chan, client, replier);
	else
	{
		if ((chan->Mode(Chan::TopicRestricted) == false) || chan->IsChop(client->Id()))
			chan->Topic(client->Id(), topic_msg->topic);
		else
			*client << replier->topic_chanoprivsneeded(chan->Title());
	}
}
