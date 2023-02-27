#include "../tests.hpp"

class	MockDB : public DatabasableMock {
	virtual bool user_is_registered(UserID *user)
	{
		(void)user;
		calls_to_user_registered++;
		return (false); //IMPORTANT
	}
};

replies_generator rp;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;

	SentMessage msg;
	msg.message = parser.parse_string("USER javgonza 4 * :Javier Gonzalez");
	msg.sender = &user;

	command_user(&db, &msg, &rp);

	if (db.calls_to_set_user_receive_wallops_mode != 1)
		return (-1);

	return (0);
}
