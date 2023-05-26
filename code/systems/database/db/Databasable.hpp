class Databasable;

#ifndef DATABASABLE_HPP
# define DATABASABLE_HPP

#include <iostream>
#include <vector>

//TODO Duplicate file from IRC_Commands repo
//TODO NOT really, but whateer, gotta clean TODOs at some point
# include "Unregistered.hpp"
# include "Client.hpp"
# include "Chan.hpp"
//#include "../../../input_stream_orquestator/SentMessage.hpp"
//#include "../../../vicmarti/src/db/Client.hpp"
//#include "../../../vicmarti/src/db/chan.hpp"
//#include "Channel/Channel.hpp"

class Databasable {
public:
	virtual void change_nick(ClientId const* user, std::string const& nick) = 0;
	virtual bool user_is_registered(ClientId const* user) = 0;
	virtual void register_user(Unregistered * user) = 0;
	virtual bool nick_is_in_use(std::string const& nick) = 0;
	virtual std::vector<ClientId> *get_all_users(void) = 0;
	virtual std::vector<ClientId> *get_all_users_and_unregistereds(void) = 0;
	virtual Client *get_user_from_user_host(std::string const&  user, std::string const& host) = 0;
	virtual Client *get_user_from_user_host(Client *client, std::string const&  user, std::string const& host) = 0;
	virtual Client *get_user_from_nickname(std::string const& nickname) = 0;
	virtual Client *get_user_from_nickname(Client *authority, std::string const& nickname) = 0;
	virtual Client *get_user_from_fd(int fd) = 0;
	virtual Unregistered* get_unregistered_from_fd(int fd) = 0;
	virtual ClientData* get_client_data_from_fd(int fd) = 0;
	virtual void new_channel(std::string const &title, ClientId const &cid) = 0;
	virtual Chan *get_channel_from_id(ChanId const &cid) = 0;
	virtual Chan *get_channel(std::string const& name) = 0;
	virtual Chan *get_channel(Client *authority, std::string const& name) = 0;
	virtual Chan *as_outsider_get_channel(Client *authority, std::string const& name) = 0;
	virtual Chan *as_outsider_get_channel_from_id(Client *authority, ChanId const &cid) = 0;
	virtual Chan *get_channel_from_id(Client *authority, const ChanId &cid) = 0;
	virtual std::vector<ClientId>	*get_all_users(Client *client) = 0;
	virtual std::vector<ChanId> *get_all_channels() = 0;
	virtual std::vector<ClientId> *get_channel_users(std::string const& channel) = 0;
	virtual std::vector<ClientId> *get_zombies(void) = 0;
	virtual Client *get_zombie(ClientId const& zid) = 0;
	virtual Client *get_zombie_from_fd(int fd) = 0;
	virtual void kill_user(ClientId *user) = 0;
	virtual void part(ClientId const &sender, ClientId const &target, ChanId const &chan) = 0;
	virtual void douse_in_holy_water(ClientId const &zid) = 0;
	//v A particular place in the hall of shame. v
	virtual Unregistered *alter_unregistered_username(Unregistered *unregistered, std::string const &username) = 0;
};

#endif
