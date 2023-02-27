class Databasable;

#ifndef DATABASABLE_HPP
# define DATABASABLE_HPP

#include <iostream>
#include <vector>

#include "../../../input_stream_orquestator/SentMessage.hpp"
#include "User/User.hpp"

class Databasable {

public:
	virtual void				change_nick(UserID *user, std::string nick) = 0;
	virtual void				set_user_invisible_mode(UserID *user) = 0;
	virtual void				set_user_receive_wallops_mode(UserID *user) = 0;
	virtual bool				user_is_registered(UserID *user) = 0;
	virtual void				register_user(UserID *user) = 0;
	virtual bool				nick_is_in_use(std::string nick) = 0;
	virtual User*				get_user_from_target() = 0;
	virtual User*				get_user_from_user_host(std::string user_str, std::string host) = 0;
	virtual User*				get_user_from_nickname(std::string nickname) = 0;
	virtual User*				get_user_from_fd(int fd) = 0;
	virtual std::vector<User>	get_channel_users(std::string channel, User *authority) = 0;
	virtual void				kill_user(UserID *user) = 0;

private:

};

#endif
