class ServerInfo;

#ifndef SERVERINFO_HPP
# define SERVERINFO_HPP

#include <iostream>

#include "../../../../input_stream_orquestator/CommandActionAssociator.hpp"

typedef struct	s_Stater {
	size_t	*calls_to_commands;
	size_t	*bytes_per_command;
	size_t	calls_to_database_get_from_fd;
}	Stater;

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
	std::string debug_lvl;
	std::string comment;
	std::string	date;

	std::string	get_preffix_string();

	void	count_command(const std::string &command, const std::string &complete_message);
	std::chrono::high_resolution_clock::time_point start_time;

private:

};

extern Stater stater;

#endif
