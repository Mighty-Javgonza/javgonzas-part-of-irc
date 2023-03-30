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
	std::string	version;
	std::string	date;

	std::string	get_preffix_string();

private:

};

#endif
