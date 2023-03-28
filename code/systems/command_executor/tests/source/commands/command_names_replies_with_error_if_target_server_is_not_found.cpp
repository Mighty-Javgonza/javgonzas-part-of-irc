#include "../tests.hpp"

UserMock namer;
UserMock namee;

class	MockChan : public ChannelMock {
};

MockChan	bienvenida_chan;
MockChan	random_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&namer);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		if (nickname == "vicmarti")
			return (&namee);
		else if (nickname == "javgonza")
			return (&namer);
		return (NULL);
	}
	std::vector<Channel *> get_all_channels()
	{
		std::vector<Channel *> channels;

		channels.push_back(&bienvenida_chan);
		channels.push_back(&random_chan);
		return (channels);
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
	namer.id.nickname = "javgonza";
	namee.id.nickname = "vicmarti";
	bienvenida_chan.name = "bienvenida";
	bienvenida_chan.user_join(&namer);
	bienvenida_chan.user_join(&namee);
	msg.message = parser.parse_string("NAMES #bienvenida doesnotexist");
	msg.sender = &user;

	command_names(&db, &msg, &rp, &server_info);

	if (namer.com.msg_out.msg_q_size() != 1)
		return (-1);

	return (0);
}
