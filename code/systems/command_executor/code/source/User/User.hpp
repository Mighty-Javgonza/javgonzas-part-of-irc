class User;

#ifndef USER_HPP
# define USER_HPP

#include "../UserID.hpp"
#include "../../../../tomartin/inc/user.hpp"

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
	~User();

	UserID	id;
	user	com;
	t_modes	modes;
	bool	register_pass_correct;

	std::string get_name() const {return "USER NAME";}
	std::string get_nickname() const {return "USER NICKNAME";}
	std::string get_email() const {return "USER@EMAIL.COM";}
	std::string get_away_msg() const {return "AWAY MSG ESTOY COMIENDO";}
	std::string get_modies() const {return "+Twx";}
	std::string get_ip() const {return "192.168.10.1";}
	std::string	get_modes_string();

	void	operator<<(std::string msg_to_send);

private:

};

#endif
