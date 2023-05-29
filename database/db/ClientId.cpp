#include "ClientId.hpp"

bool	ClientId::CompareFd(ClientId const& lhs, int const& rhs) {
	return lhs.Fd() == rhs;
}
bool	ClientId::CompareUser(ClientId const& lhs, std::string const& rhs) {
	return lhs.User() == rhs;
}
bool	ClientId::CompareHost(ClientId const& lhs, std::string const& rhs) {
	return lhs.Host() == rhs;
}

ClientId::ClientId(void) {}

ClientId::ClientId(std::string const &username, std::string const &hostname,
		const int fd) :
	__fd(fd),
	__username(username),
	__hostname(hostname) {}

ClientId::ClientId(ClientId const &rhs) {
	*this = rhs;
}

ClientId::~ClientId(void) {}

ClientId	&ClientId::operator=(ClientId const &rhs)
{
	__fd = rhs.__fd;
	__username = rhs.__username;
	__hostname = rhs.__hostname;
	return (*this);
}

bool		ClientId::operator==(ClientId const &rhs) const {
	return __fd == rhs.__fd
		&& FullHostname() == rhs.FullHostname();
}

bool		ClientId::operator<(ClientId const &rhs) const {
	if (__fd == rhs.__fd)
		return FullHostname() < rhs.FullHostname();
	return __fd < rhs.__fd;
}

int	const &ClientId::Fd(void) const {
	return __fd;
}

std::string	ClientId::User(void) const {
	return __username;
}

std::string	ClientId::Host(void) const {
	return __hostname;
}

std::string	ClientId::FullHostname(void) const {
	return __username + "@" + __hostname;
}
