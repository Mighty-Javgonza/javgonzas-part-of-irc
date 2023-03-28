#include "../tests.hpp"

UserMock moder;

class	MockChan : public ChannelMock {
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
	bienvenida_chan.name = "bienvenida";
	bienvenida_chan.user_join(&moder);
	msg.message = parser.parse_string("MODE #doesnotexit");
	msg.sender = &user;

	command_chanmode(&db, &msg, &rp, &server_info);

	if (moder.com.msg_out.msg_q_size() != 1)
		return (-1);

	return (0);
}
