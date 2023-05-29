#include "../tests.hpp"

UserMock	db_user;
class	MockDB : public DatabasableMock {
	virtual User* get_user_from_nickname(std::string nickname) {
		(void)nickname;
		calls_to_get_user_from_user_host++;

		return (NULL); //Because user does not exist
	};
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	SentMessage msg;
	msg.message = parser.parse_string("PRIVMSG javgonza Hola");
	msg.sender = &user;

	command_privmsg(&db, &msg, &rp, NULL);

	if (db_user.com.msg_out.msg_q_size() != 0)
		return (-1);

	return (0);
}

