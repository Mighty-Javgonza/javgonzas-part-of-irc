class UserMock;

#ifndef USERMOCK_HPP
# define USERMOCK_HPP

#include "../../code/source/all_headers.hpp"

class UserMock : public User {

public:
	UserMock(){};
	~UserMock(){};
	
	std::vector<Channel *>	channels;
	virtual std::vector<Channel *>	get_channels()
	{
		return (channels);
	};

private:

};

#endif
