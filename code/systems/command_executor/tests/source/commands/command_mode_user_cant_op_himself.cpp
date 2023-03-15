#include "../tests.hpp"

UserMock db_user;

class	MockDB : public DatabasableMock {
	User *get_user_from_nickname(std::string nickname)
	{
		(void)nickname;
		return (&db_user);
	}
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	user.nickname = "javgonza";
	SentMessage msg;
	msg.message = parser.parse_string("MODE javgonza +o");
	msg.sender = &user;

	command_mode(&db, &msg, &rp);

	if (db_user.modes.is_operator == true)
		return (-1);

	return (0);
}

