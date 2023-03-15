#include "../tests.hpp"

UserMock db_user;
ChannelMock	mock_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&db_user);
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

	db_user.id.nickname = "javgonza";
	mock_chan.name = "bienvenida";
	mock_chan.user_join(&db_user);
	msg.message = parser.parse_string("PART #bienvenida");
	msg.sender = &user;

	command_part(&db, &msg, &rp, &server_info);

	if (mock_chan.user_count != 0)
		return (-1);

	return (0);
}

