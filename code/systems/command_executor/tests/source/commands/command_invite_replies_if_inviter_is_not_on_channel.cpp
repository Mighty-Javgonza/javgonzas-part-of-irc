#include "../tests.hpp"

UserMock inviter;
UserMock invitee;

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
		return (&inviter);
	}
	Channel	*get_channel(std::string name)
	{
		(void)name;
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

	inviter.id.nickname = "javgonza";
	invitee.id.nickname = "vicmarti";
	mock_chan.name = "bienvenida";
	msg.message = parser.parse_string("INVITE vicmarti #darara");
	msg.sender = &user;

	command_invite(&db, &msg, &rp, &server_info);

	if (inviter.com.msg_out.msg_q_size() != 1)
		return (-1);

	if (invitee.com.msg_out.msg_q_size() != 0)
		return (-1);

	return (0);
}
