#include "ServerInfo.hpp"


ServerInfo::ServerInfo()
{
	has_password = false;
	hostname = "tvj.irc.42madrid";

	time_t now = std::time(NULL);
    char buff[100];

    std::strftime(buff, sizeof(buff), "%H:%M:%S %d-%m-%Y", std::localtime(&now));

	date += buff;

	stater.calls_to_commands = new size_t[CommandActionAssociator::get_command_count()];
	stater.bytes_per_command = new size_t[CommandActionAssociator::get_command_count()];

	for (size_t i = 0; i < CommandActionAssociator::get_command_count(); i++)
	{
		stater.calls_to_commands[i] = 0;
		stater.bytes_per_command[i] = 0;
	}
	stater.calls_to_database_get_from_fd = 0;
	start_time = std::chrono::high_resolution_clock::now();
}

ServerInfo::~ServerInfo()
{

}

std::string	ServerInfo::get_preffix_string(void)
{
	std::string	preffix;

	preffix = hostname;

	return (preffix);
}

void	ServerInfo::count_command(const std::string &command, const std::string &complete_message)
{
	size_t id = commandActionAssociator.get_command_id(command);

	stater.calls_to_commands[id]++;
	stater.bytes_per_command[id] += complete_message.length();
}

Stater stater;
