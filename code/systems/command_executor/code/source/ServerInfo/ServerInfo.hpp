class ServerInfo;

#ifndef SERVERINFO_HPP
# define SERVERINFO_HPP

#include <iostream>

class ServerInfo {

public:
	ServerInfo();
	~ServerInfo();

	std::string	motd;
	std::string	hostname;
	std::string	message_preffix;
	std::string	password;
	bool	has_password;
	std::string	oper_name;
	std::string	oper_password;

private:

};

#endif
