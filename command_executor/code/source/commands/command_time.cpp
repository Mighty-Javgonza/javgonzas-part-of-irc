#include "commands.hpp"

void	command_time(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageServerTime	*time_msg = static_cast<ParsedMessageServerTime*>(message->message);

	Client *client = database->get_user_from_fd(message->sender->Fd());
	if ((time_msg->has_target == true) && (time_msg->target.servername != server_info->hostname))
	{
		*client << replier->time_nosuchserver(time_msg->target.servername);
	}
	else
	{
		std::time_t	t = time_control::get_time();
		tm	*st = localtime(&t);
		std::stringstream	ms;
		(void) ms;
		(void) st;

//		ms << std::setfill('0') << std::setw(2) << ft_itoa(st->tm_hour) << ":" << std::setw(2) << ft_itoa(st->tm_min) << ":" << std::setw(2);
		*client << replier->time_ok(server_info->hostname, "0:0:0");
	}
}
