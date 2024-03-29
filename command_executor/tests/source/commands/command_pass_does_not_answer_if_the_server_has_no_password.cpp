#include "../tests.hpp"

UserMock db_user;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&db_user);
	}

	bool user_is_registered(UserID *user)
	{
		(void)user;
		return (false);
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

	db_user.register_pass_correct = true;
	server_info.password = "incorrect";
	server_info.has_password = false;

	msg.message = parser.parse_string("PASS foo");
	msg.sender = &user;

	command_pass(&db, &msg, &rp, &server_info);

	if (db_user.com.msg_out.msg_q_size() != 0)
		return (-1);

	return (0);
}

