class	DatabasableMock;
#ifndef DATABASABLEMOCK_HPP
# define DATABASABLEMOCK_HPP

#include "../../code/source/all_headers.hpp"

class	DatabasableMock {
public:
	int	calls_to_change_nick;
	int	calls_to_user_registered;
	int	calls_to_register_user;
	int	calls_to_nick_is_in_use;
	void	change_nick(user *usr, std::string nick) {
		(void)usr;
		(void)nick;
		calls_to_change_nick++;
	}

	bool	user_is_registered(user *usr) {
		(void) usr;
		calls_to_user_registered++;
		return (false); //Change in test
	}

	void	register_user(user *usr) {
		(void) usr;
		calls_to_register_user++;
	}

	bool nick_is_in_use(std::string nick) {
		(void) nick;
		calls_to_nick_is_in_use++;
		return (false); //Change in test
	};
};
#endif
