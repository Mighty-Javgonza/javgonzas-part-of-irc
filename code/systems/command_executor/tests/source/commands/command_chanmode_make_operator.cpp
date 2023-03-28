#include "../tests.hpp"

UserMock moder;
UserMock modee;

class	MockChan : public ChannelMock {
	public:
	bool modee_operator;

	void make_operator(User *user)
	{
		(void) user;
		modee_operator = true;
	}

	bool is_operator(User *user)
	{
		if (user->id.nickname == "javgonza")
			return (true);
		else if (user->id.nickname == "vicmarti")
			return (true);
		else
			return (false);
	}
};

MockChan	bienvenida_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&moder);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		if (nickname == "javgonza")
			return (&moder);
		else if (nickname == "vicmarti")
			return (&modee);
		return (NULL);
	}
	std::vector<Channel *> get_all_channels()
	{
		std::vector<Channel *> channels;

		channels.push_back(&bienvenida_chan);
		return (channels);
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

	server_info.hostname = "localhost";
	moder.id.nickname = "javgonza";
	modee.id.nickname = "vicmarti";
	bienvenida_chan.name = "bienvenida";
	bienvenida_chan.user_join(&moder);
	msg.message = parser.parse_string("MODE #bienvenida +o vicmarti");
	msg.sender = &user;

	command_chanmode(&db, &msg, &rp, &server_info);

	if (bienvenida_chan.is_operator(&modee) != true)
		return (-1);

	return (0);
}
