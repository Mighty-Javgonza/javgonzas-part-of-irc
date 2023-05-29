#include "../tests.hpp"

UserMock lister;
UserMock listee;

class	MockChan : public ChannelMock {
};

MockChan	bienvenida_chan;
MockChan	random_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&lister);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		if (nickname == "tomartin")
			return (&listee);
		else if (nickname == "javgonza")
			return (&lister);
		return (NULL);
	}
	std::vector<Channel *> get_all_channels()
	{
		std::vector<Channel *> channels;

		channels.push_back(&bienvenida_chan);
		channels.push_back(&random_chan);
		return (channels);
	}
	Channel	*get_channel(std::string name)
	{
		if (name == "bienvenida")
			return (&bienvenida_chan);
		else if (name == "random")
			return (&random_chan);
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
	lister.id.nickname = "javgonza";
	listee.id.nickname = "tomartin";
	bienvenida_chan.name = "bienvenida";
	bienvenida_chan.user_join(&lister);
	bienvenida_chan.user_join(&listee);
	msg.message = parser.parse_string("LIST");
	msg.sender = &user;

	command_list(&db, &msg, &rp, &server_info);

	if (lister.com.msg_out.msg_q_size() != 3)
		return (-1);

	return (0);
}
