class ChannelMock;

#ifndef CHANNELMOCK_HPP
# define CHANNELMOCK_HPP

#include "../../code/source/all_headers.hpp"

class ChannelMock : public Channel {

public:
	ChannelMock(){}
	~ChannelMock(){}

	std::vector<User> mock_users;

	std::vector<User>	get_users()
	{
		return (mock_users);
	}

	void	user_part(User *user)
	{
		(void)user;
		user_count--;
		mock_users.pop_back();
	}
	
	void	user_join(User *user)
	{
		(void)user;
		user_count++;
		mock_users.push_back(*user);
	}

	bool	user_in_chan(User *user)
	{
		for (std::vector<User>::iterator it = mock_users.begin(); it != mock_users.end(); it++)
			if (it->id.nickname == user->id.nickname)
				return (true);
		return (false);
	}

	bool	is_operator(User *user)
	{
		(void)user;
		return (false);
	}

	bool	topic_flag()
	{
		return (false);
	}

private:

};

#endif
