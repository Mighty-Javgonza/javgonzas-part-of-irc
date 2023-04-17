class Databasable;

#ifndef DATABASABLE_HPP
# define DATABASABLE_HPP

#include <iostream>
#include <vector>

#include "../../../input_stream_orquestator/SentMessage.hpp"
#include "../../../vicmarti/src/db/Client.hpp"
#include "../../../vicmarti/src/db/Unregistered.hpp"
#include "../../../vicmarti/src/db/chan.hpp"

class Databasable {

public:
	virtual void					change_nick(ClientId *user, std::string nick) = 0;
	virtual bool					user_is_registered(ClientId *user) = 0;
	virtual void					register_user(Unregistered *user) = 0;
	virtual bool					nick_is_in_use(std::string nick) = 0;
	virtual Client*					get_user_from_target() = 0;
	virtual std::vector<Client *>&	get_all_users() = 0;
	virtual Client*					get_user_from_user_host(std::string user_str, std::string host) = 0;
	virtual Client*					get_user_from_nickname(std::string nickname) = 0;
	virtual Client*					get_user_from_fd(int fd) = 0;
	virtual Unregistered*			get_unregistered_from_fd(int fd) = 0;
	virtual Chan*					get_channel(std::string name) = 0;
	virtual	std::vector<Chan *>		get_all_channels() = 0;
	virtual std::vector<Client *>	get_channel_users(std::string channel, Client *authority) = 0;
	virtual void					kill_user(Client *user) = 0;

private:

};

#endif
