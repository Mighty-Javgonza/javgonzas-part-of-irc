#include "../tests.hpp"

class	MockDB : public DatabasableMock {
public:
	bool	nick_is_in_use(std::string str) {
		(void) str;
		return (false);
	}
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	usr;

	SentMessage msg;
	msg.message = parser.parse_string("NICK Javgonza");
	msg.sender = &usr;

	command_nick(&db, &msg, &rp, NULL);

	if (db.calls_to_change_nick != 1)
		return (-1);

	return (0);
}
