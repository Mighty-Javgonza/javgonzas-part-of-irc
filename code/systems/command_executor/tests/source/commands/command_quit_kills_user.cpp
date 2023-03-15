#include "../tests.hpp"

UserMock db_user;

class	MockDB : public DatabasableMock {
	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&db_user);
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

	msg.message = parser.parse_string("QUIT");
	msg.sender = &user;

	command_quit(&db, &msg, &rp, &server_info);

	if (db.calls_to_kill_user != 1)
		return (-1);

	return (0);
}

