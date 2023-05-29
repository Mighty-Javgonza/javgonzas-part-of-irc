#ifndef CLIENT_ID_HPP
# define CLIENT_ID_HPP

# include "IComparable.hpp"

# include <string>

class ClientId : public IComparable<ClientId> {
	public:
		static bool	CompareFd(ClientId const& lhs, int const& rhs);
		static bool	CompareUser(ClientId const& lhs, std::string const& rhs);
		static bool	CompareHost(ClientId const& lhs, std::string const& rhs);

		ClientId(void);
		ClientId(std::string const &username,
				std::string const &hostname,
				const int fd);
		ClientId(ClientId const &rhs);
		~ClientId(void);
		ClientId	&operator=(ClientId const &rhs);
		bool	operator==(ClientId const &rhs) const;
		bool	operator<(ClientId const &rhs) const;
		int const &Fd(void) const;
		std::string	User(void) const;
		std::string	Host(void) const;
		std::string	FullHostname(void) const;
	private:
		int			__fd;
		std::string	__username;
		std::string	__hostname;
};
#endif

