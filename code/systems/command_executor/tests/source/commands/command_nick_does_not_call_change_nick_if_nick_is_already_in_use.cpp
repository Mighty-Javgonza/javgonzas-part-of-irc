#include "../tests.hpp"

class	MockDB : public DatabasableMock {
public:
	int	calls_to_user_registered;

	bool	user_is_registered(UserID *usr) {
		(void) usr;
		calls_to_user_registered++;
		return (true); //Important part of the test
	}

	bool	nick_is_in_use(std::string str) {
		(void) str;
		calls_to_nick_is_in_use++;
		return (true); //Important part of the test
	}
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	SentMessage msg;
	msg.message = parser.parse_string("NICK Javgonza");
	msg.sender = &user;

	command_nick((Databasable *)&db, &msg, &rp);

	if (db.calls_to_register_user != 0)
		return (-1);

	if (db.calls_to_change_nick != 0)
		return (-1);

	return (0);
}
