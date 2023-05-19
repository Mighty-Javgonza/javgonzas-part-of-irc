#include "commands.hpp"
#include <queue>

void	command_list(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelList	*list_msg = static_cast<ParsedMessageChannelList*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());

	if (list_msg->has_target)
	{
		if (list_msg->target.servername != server_info->hostname)
		{
			*client << replier->list_nosuchserver(list_msg->target.servername);
			return ;
		}
	}

	std::queue<std::pair<const std::string, const std::string> >	channel_topic_queue;
	if (list_msg->has_channels)
	{
		std::vector<channel_parameter> chans = list_msg->channel_list.channels;

		for (std::vector<channel_parameter>::iterator it = chans.begin(); it != chans.end(); it++)
		{
			Chan	*chan = database->as_outsider_get_channel(client, it->name);
			if (!chan)
				chan = database->get_channel(client, it->name);
			if (chan != NULL)
			{
				std::pair<std::string, std::string> channel_topic;
				channel_topic.first = chan->Title();
				channel_topic.second = chan->Topic();
				channel_topic_queue.push(channel_topic);
			}
		}
	}
	else
	{
		std::vector<ChanId> *all_chans = database->get_all_channels();

		for (std::vector<ChanId>::iterator it = all_chans->begin(); it != all_chans->end(); it++)
		{
			Chan *chan = database->get_channel_from_id(*it);
			std::pair<std::string, std::string> channel_topic;
			channel_topic.first = chan->Title();
			channel_topic.second = chan->Topic();
			channel_topic_queue.push(channel_topic);
		}
		delete all_chans;
	}
	*client << replier->list_ok(channel_topic_queue);
}
