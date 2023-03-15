#include "commands.hpp"

static void	try_to_reply_with_the_channel_topic(Channel *chan, User *user,replies_generator *replier)
{
	if (chan->user_in_chan(user))
	{
		if (chan->has_topic)
			*user << replier->topic_ok(*chan);
		else
			//TODO: wait for tomartin pulling
			*user << replier->topic_no(*chan);
	}
	else
		*user << replier->topic_notonchannel(*chan);
}

static void	change_channel_topic(Channel *chan, ParsedMessageChannelTopic *topic_msg)
{
	chan->topic = topic_msg->topic;
	if (topic_msg->topic == "")
		chan->has_topic = false;
}

void	command_topic(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelTopic	*topic_msg = static_cast<ParsedMessageChannelTopic*>(message->message);
	User	*user = database->get_user_from_fd(message->sender->fd);
	Channel	*chan = database->get_channel(topic_msg->channel.name);

	if (chan->topic_flag() == false)
	{
		//TODO: wait for pulling topic_nochanmodes
//		else
//			*user << replier->topic_nochanmodes(*chan);
		return ;
	}
	if (!topic_msg->has_topic)
		try_to_reply_with_the_channel_topic(chan, user, replier);
	else
	{
		if (chan->is_operator(user))
			change_channel_topic(chan, topic_msg);
		else
			*user << replier->topic_chanoprivsneeded(*chan);
	}
}
