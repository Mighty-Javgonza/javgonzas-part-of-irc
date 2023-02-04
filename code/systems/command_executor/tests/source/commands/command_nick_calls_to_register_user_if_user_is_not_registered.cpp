#include "../tests.hpp"

class	MockDB : public DatabasableMock {
public:
	bool	user_is_registered(user *usr) {
		(void) usr;
		calls_to_user_registered++;
		return (false); // Important part of the test
	}

	bool	nick_is_in_use(std::string str) {
		return (false);
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

	if (db.calls_to_register_user != 1)
		return (-1);

	return (0);
}
