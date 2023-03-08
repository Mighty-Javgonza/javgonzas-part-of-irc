#include "../tests.hpp"

User db_user;

class	MockChan : public ChannelMock {
	bool	is_operator(User *user)
	{
		return (false); //Important part of test
	}
	bool	topic_flag()
	{
		return (true);
	}
};

MockChan	mock_chan;

class	MockDB : public DatabasableMock {
	Channel	*get_channel(std::string name)
	{
		return (&mock_chan);
	}
};

replies_generator rp;

ServerInfo	server_info;

int main()
{
	MockDB	db;
	LexerParserConnector parser;
	UserID	user;
	SentMessage msg;

	db_user.id.nickname = "javgonza";
	mock_chan.name = "bienvenida";
	mock_chan.has_topic = true;
	mock_chan.topic = "A channel for discussing LOVE";
	msg.message = parser.parse_string("TOPIC #bienvenida :");
	msg.sender = &user;

	command_topic(&db, &msg, &rp, &server_info);

	if (db_user.com.msg_out.msg_q_size() != 1)
		return (-1);

	if (mock_chan.has_topic != true)
		return (-1);

	return (0);
}

