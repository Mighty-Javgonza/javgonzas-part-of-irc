class Channel;

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "../User/User.hpp"

class Channel {

public:
	Channel();
	virtual ~Channel();

	int					user_count;
	std::string			name;
	bool				has_topic;
	std::string			topic;

	virtual std::vector<User *>	get_users() = 0;
	virtual void				user_part(User *user) = 0;
	virtual void				user_join(User *user) = 0;
	virtual bool				user_in_chan(User *user) = 0;
	virtual bool				is_operator(User *user) = 0;
	virtual	bool				topic_flag() = 0;
	virtual	bool				invite_only_flag() = 0;

private:

};

#endif
