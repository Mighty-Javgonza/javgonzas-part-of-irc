class	DatabasableMock;
#ifndef DATABASABLEMOCK_HPP
# define DATABASABLEMOCK_HPP

#include "../../code/source/all_headers.hpp"
#include "UserMock.hpp"

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
	int	calls_to_get_all_users;
	int	calls_to_kill_user;

	UserMock mock_user;
	std::vector<Client *>	mock_user_vector;
	std::vector<Chan *>		mock_chan_vector;

	DatabasableMock() : calls_to_change_nick(0),
						calls_to_user_registered(0),
						calls_to_register_user(0),
						calls_to_nick_is_in_use(0),
						calls_to_get_user_from_user_host(0),
						calls_to_get_user_from_nickname(0),
						calls_to_get_user_from_fd(0),
						calls_to_get_channel_users(0),
						calls_to_get_all_users(0),
						calls_to_kill_user(0)
	{}

	virtual void	change_nick(ClientId *user, std::string nick) {
		(void)user;
		(void)nick;
		calls_to_change_nick++;
	}

	virtual bool	user_is_registered(ClientId *user) {
		(void) user;
		calls_to_user_registered++;
		return (false); //Change in test
	}

	virtual void	register_user(Client *user) {
		(void) user;
		calls_to_register_user++;
	}

	virtual bool nick_is_in_use(std::string nick) {
		(void) nick;
		calls_to_nick_is_in_use++;
		return (false); //Change in test
	};

	virtual Client* get_user_from_target() {
		return (&mock_user);
	};

	virtual Client* get_user_from_user_host(std::string user_str, std::string host) {
		(void)user_str;
		(void)host;
		calls_to_get_user_from_user_host++;
		return (&mock_user);
	};

	virtual Client* get_user_from_nickname(std::string nickname) {
		(void)nickname;
		calls_to_get_user_from_nickname++;
		return (&mock_user);
	};

	virtual Client* get_user_from_fd(int fd) {
		(void)fd;
		calls_to_get_user_from_fd++;
		return (&mock_user);
	};

	virtual std::vector<Client *>&	get_all_users() {
		calls_to_get_all_users++;

		return (mock_user_vector);
	};

	virtual std::vector<Client *> get_channel_users(std::string channel, Client *authority) {
		(void)channel;
		(void)authority;
		calls_to_get_channel_users++;
		std::vector<Client *>	users;

		users.push_back(&mock_user);

		return (users);
	};

	virtual void kill_user(Client *user) {
		(void)user;
		calls_to_kill_user++;
	};

	virtual Channel*	get_channel(std::string name) {
		(void)name;
		return (NULL);
	};

	virtual std::vector<Chan *>	get_all_channels() {
		return (mock_chan_vector);
	}
};
#endif
