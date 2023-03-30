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
	bool				topic_flag;
	bool				anonymous_flag;
	bool				invite_only_flag;
	bool				private_flag;
	bool				quiet_flag;
	bool				secret_flag;
	bool				reop_flag;

	virtual std::vector<User *>	get_users() = 0;
	virtual void				user_part(User *user) = 0;
	virtual void				user_join(User *user) = 0;
	virtual bool				user_in_chan(User *user) = 0;
	virtual bool				is_operator(User *user) = 0;
	virtual std::string			get_typed_channel_string() = 0;
	virtual void				make_operator(User *user) = 0;
	virtual void				remove_operator(User *user) = 0;

private:

};

#endif
