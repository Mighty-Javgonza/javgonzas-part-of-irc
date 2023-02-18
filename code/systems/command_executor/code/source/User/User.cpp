#include "User.hpp"


User::User() : com(0, 'a')
{

}

User::~User()
{

}

void	User::operator<<(std::string msg_to_send)
{
	com.msg_out.add_msg(msg_to_send);
}
