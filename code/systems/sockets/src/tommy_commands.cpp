#include "../inc/tommy_commands.hpp"

void	command_ping(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;

	if(parse == 0)
	{
		user.msg_out.direct_push(std::string(server.get_name() + ":" + " PONG :"
					+ server.get_name() + "\r\n"));
	}
	else if(parse == 1)
	{
		user.msg_out.add_msg(replies.ping_noorigin());
	}
	else if(parse == 2)
	{
		user.msg_out.add_msg(replies.ping_nosuchserver(server));
	}
}

void	command_pong(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;

	if(parse == 0)
	{
		user.user_times.reset_t_ping();
	}
	else if(parse == 1)
	{
		user.msg_out.add_msg(replies.ping_noorigin());
	}
	else if(parse == 2)
	{
		user.msg_out.add_msg(replies.ping_nosuchserver(server));
	}
}
		
void	command_motd(user& user, replies_generator& replies, aux_server& server)
{
	if(server.get_motd() != "")
	{
		user.msg_out.add_msg(replies.motd_ok(server));
	}
	else
	{
		user.msg_out.add_msg(replies.motd_nomotd());
	}
}

void	command_version(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;

	if(parse == 0)
	{
		user.msg_out.add_msg(replies.version_ok(server));
	}
	else
	{
		user.msg_out.add_msg(replies.version_nosuchserver(server));
	}
}

void	command_info(user& user, replies_generator& replies, aux_server& server)
{
	int	parse = 0;
	
	if(parse == 0)
	{
		user.msg_out.add_msg(replies.info_rpy(server));
	}
	else
	{
		user.msg_out.add_msg(replies.info_nosuchserver(server));
	}
}
	
void	command_time(user& user, replies_generator& replies, aux_server& server)
{
	int parse = 0;

	if(parse == 0)
	{
		std::time_t	t = time_control::get_time();
		tm	*st = localtime(&t);
		std::stringstream	ms;

		ms << std::setfill('0') << std::setw(2) << ft_itoa(st->tm_hour) << ":" 
			<< std::setw(2) << ft_itoa(st->tm_min) << ":" << std::setw(2) 
			<< ft_itoa(st->tm_sec);
		user.msg_out.add_msg(replies.time_ok(server, ms.str()));

	}
	else
	{
		user.msg_out.add_msg(replies.time_nosuchserver(server));
	}
}
