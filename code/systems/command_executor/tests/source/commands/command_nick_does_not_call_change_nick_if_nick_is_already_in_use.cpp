#include "../tests.hpp"

class	MockDB : public DatabasableMock {
public:
	int	calls_to_user_registered;

	bool	user_is_registered(user *usr) {
		(void) usr;
		calls_to_user_registered++;
		return (true); //Important part of the test
	}

	bool	nick_is_in_use(std::string *str) {
		(void) str;
		calls_to_nick_is_in_use++;
		return (true); //Important part of the test
	}
};

class	MockReplier : public Replierable {
};

CommandActionAssociator commandActionAssociator;

int main()
{
	MockDB	db;
	MockReplier	rp;
	LexerParserConnector parser;
	user	usr(0, 'a');

	SentMessage msg;
	msg.message = parser.parse_string("NICK Javgonza");
	msg.sender = &usr;

	command_nick(&db, &msg, &rp);

	if (db.calls_to_register_user != 0)
		return (-1);

	if (db.calls_to_change_nick != 0)
		return (-1);

	return (0);
}
