#include "../tests.hpp"

UserMock db_user;

class	MockDB : public DatabasableMock {
	User *get_user_from_nickname(std::string nickname)
	{
		(void)nickname;
		return (NULL);
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
	msg.message = parser.parse_string("MODE javgonza");
	msg.sender = &user;

	command_mode(&db, &msg, &rp, NULL);

	if (db_user.com.msg_out.msg_q_size() != 0)
		return (-1);

	return (0);
}

