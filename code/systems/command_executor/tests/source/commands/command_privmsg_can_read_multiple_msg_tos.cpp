#include "../tests.hpp"

class	MockDB : public DatabasableMock {
	UserMock	user;
	virtual User* get_user_from_user_host(std::string user_str, std::string host) {
		(void)user_str;
		(void)host;
		calls_to_get_user_from_user_host++;

		return (&user);
	};
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	SentMessage msg;
	msg.message = parser.parse_string("PRIVMSG javgonza,tomartin,vicmarti :Hola");
	msg.sender = &user;

	command_privmsg(&db, &msg, &rp);

	if (db.calls_to_get_user_from_nickname!= 3)
		return (-1);

	return (0);
}
