#include "../tests.hpp"

UserMock inviter;
UserMock invitee;

class	MockChan : public ChannelMock {
	bool	is_operator(User *user)
	{
		(void)user;
		return (false); //Important part of test
	}
	bool	invite_only_flag()
	{
		return (true); //Important part of test
	}
};

MockChan	mock_chan;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&inviter);
	}
	User *get_user_from_nickname(std::string nickname)
	{
		(void)nickname;
		return (&invitee);
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

	inviter.id.nickname = "javgonza";
	invitee.id.nickname = "vicmarti";
	mock_chan.name = "bienvenida";
	mock_chan.user_join(&inviter);
	msg.message = parser.parse_string("INVITE vicmarti #bienvenida");
	msg.sender = &user;

	command_invite(&db, &msg, &rp, &server_info);

	if (inviter.com.msg_out.msg_q_size() != 1)
		return (-1);

	if (invitee.com.msg_out.msg_q_size() != 0)
		return (-1);

	return (0);
}
