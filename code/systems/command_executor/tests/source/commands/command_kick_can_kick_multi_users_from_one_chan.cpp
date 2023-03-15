#include "../tests.hpp"

UserMock kicker;
UserMock kickee_b;
UserMock kickee_r;

class	MockChan : public ChannelMock {
	bool	is_operator(User *user)
	{
		(void)user;
		return (true);
	}
};

MockChan	bienvenida_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&kicker);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		if (nickname == "vicmarti")
			return (&kickee_b);
		else if (nickname == "tomartin")
			return (&kickee_r);
		else if (nickname == "javgonza")
			return (&kicker);
		return (NULL);
	}
	Channel	*get_channel(std::string name)
	{
		if (name == "bienvenida")
			return (&bienvenida_chan);
		return (NULL);
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
	kickee_b.id.nickname = "vicmarti";
	kickee_r.id.nickname = "tomartin";
	bienvenida_chan.name = "bienvenida";
	bienvenida_chan.user_join(&kicker);
	bienvenida_chan.user_join(&kickee_b);
	bienvenida_chan.user_join(&kickee_r);
	msg.message = parser.parse_string("KICK #bienvenida vicmarti,tomartin");
	msg.sender = &user;

	command_kick(&db, &msg, &rp, &server_info);

	if (bienvenida_chan.user_count != 1)
		return (-1);

	return (0);
}
