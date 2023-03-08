#include "../tests.hpp"

User db_user;

class	MockDB : public DatabasableMock {
	virtual bool user_is_registered(UserID *user)
	{
		(void)user;
		calls_to_user_registered++;
		return (false); //IMPORTANT
	}

	User *get_user_from_fd(int fd)
	{
		(void)fd;
		return (&db_user);
	}
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	SentMessage msg;
	msg.message = parser.parse_string("USER javgonza 12 * :Javier Gonzalez");
	msg.sender = &user;

	command_user(&db, &msg, &rp);

	if (db_user.modes.receive_wallops != 1)
		return (-1);

	if (db_user.modes.invisible != 1)
		return (-1);

	return (0);
}
