class Databasable;

#ifndef DATABASABLE_HPP
# define DATABASABLE_HPP

#include <iostream>

#include "../../../input_stream_orquestator/SentMessage.hpp"

class Databasable {

public:
	virtual void	change_nick(user *usr, std::string nick) = 0;
	virtual bool	user_is_registered(user *usr) = 0;
	virtual void	register_user(user *usr) = 0;
	virtual bool	nick_is_in_use(std::string nick) = 0;

private:

};

#endif
