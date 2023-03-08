#include "User.hpp"

User::User() : com(0, 'a', "null.null")
{
	modes = (t_modes){false, false, false, false, false, false, false};
	register_pass_correct = false;
}

User::~User()
{

}

void	User::operator<<(std::string msg_to_send)
{
	com.msg_out.add_msg(msg_to_send);
}

std::string	User::get_modes_string(void)
{
	std::string	modes_str = "";

	if (modes.away)
		modes_str += "a";
	if (modes.invisible)
		modes_str += "i";
	if (modes.receive_wallops)
		modes_str += "w";
	if (modes.restricted_user_connection)
		modes_str += "r";
	if (modes.is_operator)
		modes_str += "o";
	if (modes.local_operator)
		modes_str += "O";
	if (modes.server_notices)
		modes_str += "s";
	return (modes_str);
}
std::string	User::get_preffix_string(void)
{
	std::string	preffix;

	preffix = id.nickname + "!" + id.user + "@" + id.hostname;
	return (preffix);
}

void	User::set_username(std::string username)
{
	id.user = username;
}

void	User::set_hostname(std::string hostname)
{
	id.hostname = hostname;
}

void	User::set_realname(std::string realname)
{
	id.realname = realname;
}

void	User::set_invisible_mode(void)
{
	modes.invisible = true;
}

void	User::set_receive_wallops_mode(void)
{
	modes.receive_wallops = true;
}
