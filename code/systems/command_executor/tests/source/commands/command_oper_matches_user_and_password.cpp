#include "../tests.hpp"

User db_user;

class	MockDB : public DatabasableMock {
	User *get_user_from_nickname(std::string nickname)
	{
		(void)nickname;
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

	server_info.oper_name = "foo";
	server_info.oper_password = "1234";
	user.nickname = "javgonza";
	SentMessage msg;
	db_user.modes.restricted_user_connection = true;
	msg.message = parser.parse_string("OPER foo 1234");
	msg.sender = &user;

	command_oper(&db, &msg, &rp, &server_info);

	if (db_user.modes.local_operator != true)
		return (-1);

	return (0);
}

