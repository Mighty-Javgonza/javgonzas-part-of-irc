class User;

#ifndef USER_HPP
# define USER_HPP

#include "../UserID.hpp"
#include "../../../../tomartin/inc/user.hpp"
#include "../Channel/Channel.hpp"

typedef struct	s_modes
{
	bool	away;
	bool	invisible;
	bool	receive_wallops;
	bool	restricted_user_connection;
	bool	is_operator;
	bool	local_operator;
	bool	server_notices;
}				t_modes;

class User {

public:
	User();
	virtual ~User();

	UserID	id;
	user	com;
	t_modes	modes;
	std::string	away_msg;
	bool	register_pass_correct;

	std::string get_preffix_string();
	void		set_username(std::string username);
	void		set_hostname(std::string hostname);
	void		set_realname(std::string nickname);

	void		set_invisible_mode();
	void		set_receive_wallops_mode();

	virtual std::vector<Channel *>	get_channels() = 0;

	std::string	get_modes_string();

	void	operator<<(std::string msg_to_send);

private:

};

#endif
