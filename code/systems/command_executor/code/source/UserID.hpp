typedef struct s_UserID UserID;

#ifndef USERID_HPP
# define USERID_HPP

#include <iostream>

typedef struct s_UserID {
	int			fd;
	std::string nickname;
	std::string user;
	std::string host;
} UserID;

#endif
