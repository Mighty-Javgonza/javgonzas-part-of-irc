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
	msg.message = parser.parse_string("USER javgonza 0 * :Javier Gonzalez");
	msg.sender = &user;

	command_user(&db, &msg, &rp);

	if (db.calls_to_user_registered != 1)
		return (-1);

	if (db.calls_to_register_user != 1)
		return (-1);

	if (db.mock_user.com.msg_out.msg_q_size() != 1)

	return (0);
}
