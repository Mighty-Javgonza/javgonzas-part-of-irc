class MessageConnectionPrivmsgParser;

#ifndef MESSAGECONNECTIONPRIVMSGPARSER_HPP
# define MESSAGECONNECTIONPRIVMSGPARSER_HPP

#include "../MessageParser.hpp"

# include "../../ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesPrivmsg.hpp"

class MessagePrivateMessagesPrivmsgParser : public MessageParser{

public:
	MessagePrivateMessagesPrivmsgParser();
	~MessagePrivateMessagesPrivmsgParser();

	ParsedMessagePrivateMessagesPrivmsg	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
