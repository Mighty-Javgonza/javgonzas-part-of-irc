#include "../tests.hpp"

UserMock kicker;
UserMock kickee;

class	MockChan : public ChannelMock {
	bool	is_operator(User *user)
	{
		(void)user;
		return (true);
	}
};

MockChan	mock_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&kicker);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		(void)nickname;
		if (nickname == "javgonza")
			return (&kicker);
		else if (nickname == "vicmarti")
			return (&kickee);
		return (NULL);
	}
	Channel	*get_channel(std::string name)
	{
		(void)name;
		return (&mock_chan);
	}
};

replies_generator rp;

ServerInfo	server_info;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;
	SentMessage msg;

	kicker.id.nickname = "javgonza";
	kickee.id.nickname = "vicmarti";
	mock_chan.name = "bienvenida";
	mock_chan.user_join(&kicker);
	mock_chan.user_join(&kickee);
	msg.message = parser.parse_string("KICK #bienvenida vicmarti");
	msg.sender = &user;

	command_kick(&db, &msg, &rp, &server_info);

	if (kicker.com.msg_out.msg_q_size() != 1)
		return (-1);

	if (kickee.com.msg_out.msg_q_size() != 1)
		return (-1);

	if (mock_chan.user_count != 1)
		return (-1);

	return (0);
}
