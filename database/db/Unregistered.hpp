#ifndef UNREGISTERED_HPP
# define UNREGISTERED_HPP

# include "IComparable.hpp"
# include "ClientData.hpp"
# include "Client.hpp"

class Unregistered : public ClientData
{
	public:
		static bool	CompareNick(Unregistered const& lhs,
				std::string const &rhs);
		static bool	CompareFd(Unregistered const& lhs, int const &rhs);

		Unregistered(void);
		Unregistered(ClientId const &id, bool valid_pass = false);
		Unregistered(Unregistered const &rhs);
		~Unregistered(void);
		Unregistered	&operator=(Unregistered const &rhs);
		void	ValidatePass(void);
		bool	IsReady(void) const;
		bool	__valid_pass;
};
#endif
