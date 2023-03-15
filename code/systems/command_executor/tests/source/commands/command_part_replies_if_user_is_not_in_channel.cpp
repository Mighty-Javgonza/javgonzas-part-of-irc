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

	mock_chan.name = "bienvenida";
	msg.message = parser.parse_string("PART #bienvenida");
	msg.sender = &user;

	command_part(&db, &msg, &rp, &server_info);

	if (db_user.com.msg_out.msg_q_size() != 1)
		return (-1);

	return (0);
}

