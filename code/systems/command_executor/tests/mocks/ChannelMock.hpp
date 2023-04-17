class ChannelMock;

#ifndef CHANNELMOCK_HPP
# define CHANNELMOCK_HPP

#include "../../code/source/all_headers.hpp"
#include "../../../../vicmarti/src/db/Client.hpp"

class ChannelMock : public Channel {

public:
	ChannelMock(){}
	~ChannelMock(){}

	std::vector<Client *> mock_users;

	std::vector<Client *>	get_users()
	{
		return (mock_users);
	}

	void	user_part(Client *user)
	{
		(void)user;
		user_count--;
		mock_users.pop_back();
	}
	
	void	user_join(Client *user)
	{
		(void)user;
		user_count++;
		mock_users.push_back(user);
	}

	bool	user_in_chan(Client *user)
	{
		for (std::vector<Client *>::iterator it = mock_users.begin(); it != mock_users.end(); it++)
		{
			if ((*it)->id.nickname == user->id.nickname)
				return (true);
		}
		return (false);
	}

	bool	is_operator(Client *user)
	{
		(void)user;
		return (false);
	}

	std::string	get_typed_channel_string()
	{
		if (secret_flag)
			return ("@" + name);
		if (private_flag)
			return ("*" + name);
		else
			return ("=" + name);
	}

	void make_operator(Client *user)
	{
		(void)user;
	}

	void remove_operator(Client *user)
	{
		(void)user;
	}


private:

};

#endif
