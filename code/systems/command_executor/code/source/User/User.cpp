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
