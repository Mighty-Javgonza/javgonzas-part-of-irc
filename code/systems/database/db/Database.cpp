#include "Database.hpp"
#include "exceptions/InvalidState.hpp"

Database::Database(void) {}

Database::~Database(void) {}

IndexedRegisterKeeper<ClientId, Unregistered>
	&Database::UnregisteredClients(void) {
	return __unregistereds;
}

IndexedRegisterKeeper<ClientId, Client> &Database::Clients(void) {
	return __clients;
}

IndexedRegisterKeeper<ChanId, Chan> &Database::Channels(void) {
	return __chans;
}

IndexedRegisterKeeper<ClientId, Client> &Database::Zombies(void) {
	return __zombies;
}

void	Database::change_nick(ClientId const* cid, std::string const& nick) {
	try {
		if (__clients.IdExists(*cid)) {
			__clients.Find(*cid).Nick(nick);
		} else if (__unregistereds.IdExists(*cid)) {
			__unregistereds.Find(*cid).Nick(nick);
		}
	} catch (std::out_of_range const& oor) {
		std::cerr << oor.what() << std::endl;
	}
}

bool	Database::user_is_registered(ClientId const* cid) {
	return __clients.IdExists(*cid);
}

void	Database::register_user(Unregistered *unreg) {
	if (__clients.IdExists(unreg->Id())) {
		std::cerr << "Client already registered." << std::endl;
		return ;
	}
	//TODO Control exit codes
	if (__clients.Insert(Client(*unreg))) {
		__unregistereds.Remove(unreg->Id());
	}
}

bool	Database::nick_is_in_use(std::string const& nick) {
	return __clients.RegisterExists(nick, &Client::CompareNick)
		|| __unregistereds.RegisterExists(nick, &Unregistered::CompareNick);
}

std::vector<ClientId>	*Database::get_all_users(void) {
	return Clients().Vector();
}

std::vector<ClientId>	*Database::get_all_users_and_unregistereds(void) {
	std::vector<ClientId> *all_client_ids = Clients().Vector();
	std::vector<ClientId> *all_unregistered_ids = UnregisteredClients().Vector();

	all_client_ids->insert(all_client_ids->end(),
			all_unregistered_ids->begin(),
			all_unregistered_ids->end());
	delete all_unregistered_ids;
	return all_client_ids;
}

Client	*Database::get_user_from_user_host(std::string const& user,
		std::string const& host) {
	const std::string			userhost = user + "@" + host;
	Client						*request = NULL;

	if (Clients().RegisterExists<std::string>(userhost,
				Client::CompareUserHost)) {
		try {
		const ClientId &target_cid = Clients().IdOf<std::string>(userhost,
				Client::CompareUserHost);
		request = &(Clients().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<std::string>."
			<< std::endl;
		request = NULL;
		}
	}
	return request;
}

Client	*Database::get_user_from_nickname(std::string const& nick) {
	Client						*request = NULL;

	if (Clients().RegisterExists<std::string>(nick, Client::CompareNick)) {
		try {
		const ClientId &target_cid = Clients().IdOf<std::string>(nick,
				Client::CompareNick);
		request = &(Clients().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<std::string>."
			<< std::endl;
		request = NULL;
		}
	}
	return request;
}

Client	*Database::get_user_from_fd(int fd) {
	Client						*request = NULL;

	if (Clients().RegisterExists<int>(fd, Client::CompareFd)) {
		try {
		const ClientId &target_cid = Clients().IdOf<int>(fd, Client::CompareFd);
		request = &(Clients().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<int>." << std::endl;
		request = NULL;
		}
	}
	return request;
}

Unregistered	*Database::get_unregistered_from_fd(int fd) {
	Unregistered						*request = NULL;

	if (UnregisteredClients().RegisterExists<int>(fd, Unregistered::CompareFd)) {
		try {
		const ClientId &target_cid =
			UnregisteredClients().IdOf<int>(fd, Unregistered::CompareFd);
		request = &(UnregisteredClients().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<int>." << std::endl;
		request = NULL;
		}
	}
	return request;
}

ClientData	*Database::get_client_data_from_fd(int fd) {
	ClientData	*request = get_unregistered_from_fd(fd);
	if (!request)
		request = get_user_from_fd(fd);
	if (!request)
		request = get_zombie_from_fd(fd);
	return request;
}

void	Database::new_channel(std::string const &title, ClientId const &cid) {
	if (get_channel(title) || !Clients().IdExists(cid)) {
		std::cerr << "Impossible to create channel." << std::endl;
		return ;
	}
	Client *creator = NULL;
	try {
		creator = &Clients().Find(cid);
	} catch (...) {
		std::cerr << "OOR after sucessful RegisterExists<string>." << std::endl;
		return ;
	}
	Chan	new_chan(title, *creator);
	Channels().Insert(new_chan);
}

Chan*	Database::get_channel_from_id(ChanId const &cid) {
	Chan	*request = NULL;

	if (Channels().IdExists(cid)) {
		try {
		request = &(Channels().Find(cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful IdExists."
			<< std::endl;
		request = NULL;
		}
	}
	return request;
}
Chan	*Database::get_channel(std::string const& name) {
	Chan	*request = NULL;

	if (Channels().RegisterExists<std::string>(name, Chan::CompareName)) {
		try {
		const ChanId &target_cid = Channels().IdOf<std::string>(name,
				Chan::CompareName);
		request = &(Channels().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<std::string>."
			<< std::endl;
		request = NULL;
		}
	} else {
		std::cerr << "Channel not found: " << name
			<< std::endl;
	}
	return request;
}

std::vector<ChanId>	*Database::get_all_channels(void) {
	return Channels().Vector();
}

std::vector<ClientId>	*Database::get_channel_users(std::string const& channel) {
	std::vector<ClientId>	*request = NULL;

	if (Channels().RegisterExists<std::string>(channel, Chan::CompareName)) {
		try {
		const ChanId &target_cid = Channels().IdOf<std::string>(channel,
				Chan::CompareName);
		request = Channels().Find(target_cid).Subscribers();
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<std::string>."
			<< std::endl;
		request = NULL;
		}
	}
	return request;
}

std::vector<ClientId> *Database::get_zombies(void) {
	return Zombies().Vector();
}

Client *Database::get_zombie(ClientId const& zid) {
	Client	*request = NULL;

	if (Zombies().IdExists(zid)) {
		try {
		request = &(Zombies().Find(zid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful IdExists."
			<< std::endl;
		request = NULL;
		}
	}
	return request;
}

Client *Database::get_zombie_from_fd(int fd) {
	Client	*request = NULL;

	if (Zombies().RegisterExists<int>(fd, Client::CompareFd)) {
		try {
		const ClientId &target_cid =
			Zombies().IdOf<int>(fd, Client::CompareFd);
		request = &(Zombies().Find(target_cid));
		} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful RegisterExists<int>." << std::endl;
		request = NULL;
		}
	}
	return request;
}

void	Database::kill_user(ClientId * cid) {
	if (!__clients.IdExists(*cid))
		return ;
	Client target = __clients.Find(*cid);
	if (!target.CanQuit())
		throw InvalidState("User left while subscribed to channels.");
	Zombies().Insert(target);
	__clients.Remove(*cid);
}

void Database::part(ClientId const &sender, ClientId const &target, ChanId const &chan) {
	if (!(Clients().IdExists(sender)
				&& Clients().IdExists(target)
				&& Channels().IdExists(chan))) {
		std::cerr << "Your parameters are wrong. __LENNY_FACE__" << std::endl;
		return ;
	}
	try {
		Client &full_target = Clients().Find(target);
		Chan &full_chan = Channels().Find(chan);
		full_chan.Leave(sender, full_target);
		if (full_chan.IsEmpty()) {
			Channels().Remove(chan);
		}
	} catch (std::out_of_range const& oor) {
		std::cerr << "OOR after sucessful IdExists."
			<< std::endl;
		return ;
	}
}

void Database::douse_in_holy_water(ClientId const &zid) {
	if (!Zombies().IdExists(zid)) {
		std::cerr << "That was not a zombie!" << std::endl;
		return ;
	}
	Zombies().Remove(zid);
}

Unregistered *Database::alter_unregistered_username(Unregistered *unregistered,
		std::string const &username) {
	msg msg_in_copy(unregistered->msg_in);
	msg msg_out_copy(unregistered->msg_out);

	const ClientId	&uid = unregistered->Id();
	if (!UnregisteredClients().IdExists(uid))
		return NULL;
	Unregistered	updated_unreg(ClientId(username, uid.Host(), uid.Fd()), true);
	updated_unreg.Nick(unregistered->Nick());
	updated_unreg.Name(unregistered->Name());
	updated_unreg.msg_in = msg_in_copy;
	updated_unreg.msg_out = msg_out_copy;
	UnregisteredClients().Remove(uid);
	UnregisteredClients().Insert(updated_unreg);
	try {
		return &UnregisteredClients().Find(updated_unreg.Id());
	} catch (std::out_of_range const& oor) {
		std::cerr << "OOR during alter username." << std::endl;
	}
	return NULL;
}
