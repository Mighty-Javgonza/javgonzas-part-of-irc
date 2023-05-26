#ifndef DATABASE_HPP
# define DATABASE_HPP

# include "Databasable.hpp"
# include "IndexedRegisterKeeper.hpp"
# include "Unregistered.hpp"
# include "Client.hpp"
# include "Chan.hpp"

class Database : public Databasable {
public:
	Database(void);
	virtual ~Database(void);
	IndexedRegisterKeeper<ClientId, Unregistered>	&UnregisteredClients(void);
	IndexedRegisterKeeper<ClientId, Client>				&Clients(void);
	IndexedRegisterKeeper<ChanId, Chan>						&Channels(void);
	IndexedRegisterKeeper<ClientId, Client>				&Zombies(void);

	//FROM DATABASABLE vvvv TODO
	void change_nick(ClientId const* user, std::string const& nick);
	bool user_is_registered(ClientId const* user);
	void register_user(Unregistered *user);
	bool nick_is_in_use(std::string const& nick);
	std::vector<ClientId> *get_all_users(void);
	std::vector<ClientId> *get_all_users_and_unregistereds(void);
	Client *get_user_from_user_host(std::string const&  user, std::string const& host);
	Client *get_user_from_nickname(std::string const& nickname);
	Client *get_user_from_fd(int fd);
	Unregistered* get_unregistered_from_fd(int fd);
	ClientData* get_client_data_from_fd(int fd);
	void new_channel(std::string const &title, ClientId const &cid);
	Chan *get_channel_from_id(ChanId const &cid);
	Chan *get_channel(std::string const& name);
	std::vector<ChanId> *get_all_channels();
	std::vector<ClientId> *get_channel_users(std::string const& channel);
	std::vector<ClientId> *get_zombies(void);
	Client *get_zombie(ClientId const& zid);
	Client *get_zombie_from_fd(int fd);
	void kill_user(ClientId *user);
	void part(ClientId const &sender, ClientId const &target, ChanId const &chan);
	void douse_in_holy_water(ClientId const &zid);
	//v A particular place in the hall of shame. v
	Unregistered *alter_unregistered_username(Unregistered *unregistered, std::string const &username);
private:
	IndexedRegisterKeeper<ClientId, Unregistered>	__unregistereds;
	IndexedRegisterKeeper<ClientId, Client>				__clients;
	IndexedRegisterKeeper<ChanId, Chan>						__chans;
	IndexedRegisterKeeper<ClientId, Client>				__zombies;
};
#endif
