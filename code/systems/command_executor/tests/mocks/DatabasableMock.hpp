class	DatabasableMock;
#ifndef DATABASABLEMOCK_HPP
# define DATABASABLEMOCK_HPP

#include "../../code/source/all_headers.hpp"

class	DatabasableMock : public Databasable{
public:
	int	calls_to_change_nick;
	int	calls_to_user_registered;
	int	calls_to_register_user;
	int	calls_to_nick_is_in_use;
	int	calls_to_get_user_from_user_host;
	int	calls_to_get_user_from_nickname;
	int	calls_to_get_user_from_fd;
	int	calls_to_get_channel_users;
	int	calls_to_kill_user;

	DatabasableMock() : calls_to_change_nick(0),
						calls_to_user_registered(0),
						calls_to_register_user(0),
						calls_to_nick_is_in_use(0),
						calls_to_get_user_from_user_host(0),
						calls_to_get_user_from_nickname(0),
						calls_to_get_user_from_fd(0),
						calls_to_get_channel_users(0),
						calls_to_kill_user(0)
	{}

	virtual void	change_nick(UserID *user, std::string nick) {
		(void)user;
		(void)nick;
		calls_to_change_nick++;
	}

	virtual bool	user_is_registered(UserID *user) {
		(void) user;
		calls_to_user_registered++;
		return (false); //Change in test
	}

	virtual void	register_user(UserID *user) {
		(void) user;
		calls_to_register_user++;
	}

	virtual bool nick_is_in_use(std::string nick) {
		(void) nick;
		calls_to_nick_is_in_use++;
		return (false); //Change in test
	};

	virtual User get_user_from_target() {
		User	user;

		return (user);
	};

	virtual User get_user_from_user_host(std::string user_str, std::string host) {
		(void)user_str;
		(void)host;
		calls_to_get_user_from_user_host++;
		User	user;

		return (user);
	};

	virtual User get_user_from_nickname(std::string nickname) {
		(void)nickname;
		calls_to_get_user_from_nickname++;
		User	user;

		return (user);
	};

	virtual User get_user_from_fd(int fd) {
		(void)fd;
		calls_to_get_user_from_fd++;
		User	user;

		return (user);
	};

	virtual std::vector<User> get_channel_users(std::string channel) {
		(void)channel;
		calls_to_get_channel_users++;
		User	user;
		std::vector<User>	users;

		users.push_back(user);

		return (users);
	};

	virtual void kill_user(UserID *user) {
		(void)user;
		calls_to_kill_user++;
	};
};
#endif
