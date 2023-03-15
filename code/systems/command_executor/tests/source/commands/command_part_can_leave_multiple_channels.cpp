#include "../tests.hpp"

UserMock db_user;
ChannelMock	mock_chan_welcome;
ChannelMock	mock_chan_random;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&db_user);
	}

	Channel	*get_channel(std::string name)
	{
		(void)name;
		if (name == "bienvenida")
			return (&mock_chan_welcome);
		else if (name == "random")
			return (&mock_chan_random);
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

	db_user.id.nickname = "javgonza";
	mock_chan_welcome.name = "bienvenida";
	mock_chan_random.name = "random";
	mock_chan_welcome.user_join(&db_user);
	mock_chan_random.user_join(&db_user);
	msg.message = parser.parse_string("PART #bienvenida,#random");
	msg.sender = &user;

	command_part(&db, &msg, &rp, &server_info);

	if (mock_chan_welcome.user_count != 0)
		return (-1);

	if (mock_chan_random.user_count != 0)
		return (-1);

	return (0);
}

