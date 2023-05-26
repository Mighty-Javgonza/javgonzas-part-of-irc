#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "IComparable.hpp"
# include "ClientData.hpp"
# include "ChanId.hpp"

# include <string>
# include <vector>
# include <set>

class Client : public ClientData
{
	public:
		static bool	CompareUserHost(Client const& lhs, std::string const &rhs);
		static bool	CompareNick(Client const& lhs, std::string const& rhs);
		static bool	CompareFd(Client const& lhs, int const &rhs);

		Client(void);
		Client(Client const& rhs);
		Client(ClientData const& rhs);
		~Client(void);
		Client	&operator=(Client const& rhs);
		bool	Join(ChanId const& cid);
		void	Leave(ChanId const& cid);
		std::vector<ChanId>	*Subscriptions(void) const;
		bool	CanQuit(void) const;
	private:
		//Hiding functionality
		using ClientData::Name;

		static unsigned int	__max_chans;

		std::set<ChanId>	__subscriptions;
};
#endif
