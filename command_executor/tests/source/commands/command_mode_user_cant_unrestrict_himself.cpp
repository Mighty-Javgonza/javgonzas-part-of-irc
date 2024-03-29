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
	db_user.modes.restricted_user_connection = true;
	msg.message = parser.parse_string("MODE javgonza -r");
	msg.sender = &user;

	command_mode(&db, &msg, &rp, NULL);

	if (db_user.modes.restricted_user_connection == false)
		return (-1);

	return (0);
}

