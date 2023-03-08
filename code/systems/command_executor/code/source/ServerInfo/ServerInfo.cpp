#include "ServerInfo.hpp"


ServerInfo::ServerInfo()
{
	has_password = false;
	hostname = "localhost";
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
