#include "commands.hpp"
#include <queue>

void	command_list(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)server_info;
	ParsedMessageChannelList	*list_msg = static_cast<ParsedMessageChannelList*>(message->message);
	User *user = database->get_user_from_fd(message->sender->fd);

	if (list_msg->has_target)
	{
		if (list_msg->target.servername != server_info->hostname)
		{
			*user << replier->list_nosuchserver(list_msg->target.servername);
			return ;
		}
	}

	std::queue<std::string>	channel_queue;
	std::queue<std::string>	topic_queue;
	if (list_msg->has_channels)
	{
		std::vector<channel_parameter> chans = list_msg->channel_list.channels;

		for (std::vector<channel_parameter>::iterator it = chans.begin(); it != chans.end(); it++)
		{
			Channel	*chan = database->get_channel(it->name);
			if (chan != NULL)
			{
				channel_queue.push(chan->name);
				topic_queue.push(chan->topic);
			}
		}
	}
	else
	{
		std::vector<Channel *> all_chans = database->get_all_channels();

		for (std::vector<Channel *>::iterator it = all_chans.begin(); it != all_chans.end(); it++)
		{
			channel_queue.push((*it)->name);
			topic_queue.push((*it)->topic);
		}
	}
	*user << replier->list_ok(channel_queue, topic_queue);
}
