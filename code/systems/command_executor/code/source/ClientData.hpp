#ifndef CLIENT_DATA_HPP
# define CLIENT_DATA_HPP

# include "IIndexed.hpp"
# include "IComparable.hpp"
# include "ClientId.hpp"
# include "exceptions/InvalidState.hpp"

//TODO Dirty add of user (user pequenito) into includes
#include "../../../sockets/inc/msg.hpp"
#include "../../../sockets/inc/time_control.hpp"
//TODO ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

# include <string>
# include <vector>

class ClientData : public IComparable<ClientData> , public IIndexed<ClientId>
{
	public:
		enum	UserMode {
			Invisible = 0,
			ServerNotice = 1,
			Wallops = 2,
			Operator = 3,
			LocalOperator = 4,
			MODE_SIZE = 5
		};

		static bool	CompareUserHost(ClientData const& lhs,
				std::string const &rhs);
		static bool	CompareNick(ClientData const& lhs, std::string const &rhs);
		static bool	CompareFd(ClientData const& lhs, int const &rhs);

		time_control	user_times;
		msg				msg_in;
		msg				msg_out;

		ClientData(void);
		ClientData(ClientId const &rhs);
		ClientData(ClientData const &rhs);
		virtual ~ClientData(void);
		ClientData	&operator=(ClientData const &rhs);
		bool	operator==(ClientData const &rhs) const;
		bool	operator<(ClientData const &rhs) const;
		void	operator<<(std::string const &message);
		ClientId const	&Id(void) const;
		void	Nick(std::string const &nick);
		const std::string	&Nick(void) const;
		void	Name(std::string const &name);
		const std::string	&Name(void) const;
		std::string	MessagePrefix(void) const throw (InvalidState);
		bool	Mode(UserMode const mode) const;
		void	Mode(UserMode const mode, bool value);
		std::string	ModeString(void) const;
	protected:
		ClientId				_id;
		std::string				_nickname;
		std::string				_realname;
		std::vector<bool>		_mode_flags;
};
#endif
