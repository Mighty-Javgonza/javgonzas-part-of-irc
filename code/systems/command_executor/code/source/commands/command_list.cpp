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
			Chan	*chan = database->get_channel(it->name);
			if (chan != NULL)
			{
				std::pair<std::string, std::string> channel_topic;
				channel_topic.first = chan->Name();
				channel_topic.second = chan->topic;
				channel_topic_queue.push(channel_topic);
			}
		}
	}
	else
	{
		std::vector<Chan *> all_chans = database->get_all_channels();

		for (std::vector<Chan *>::iterator it = all_chans.begin(); it != all_chans.end(); it++)
		{
			std::pair<std::string, std::string> channel_topic;
			channel_topic.first = (*it)->Name();
			channel_topic.second = (*it)->topic;
			channel_topic_queue.push(channel_topic);
		}
	}
	*client << replier->list_ok(channel_topic_queue);
}
