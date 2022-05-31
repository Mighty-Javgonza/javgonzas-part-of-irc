class MessagePrivateMessagesNoticeParser;

#ifndef MESSAGEPRIVATEMESSAGESNOTICEPARSER_HPP
# define MESSAGEPRIVATEMESSAGESNOTICEPARSER_HPP

#include "../MessageParser.hpp"

# include "../../ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesNotice.hpp"

class MessagePrivateMessagesNoticeParser : public MessageParser {

public:
	MessagePrivateMessagesNoticeParser();
	~MessagePrivateMessagesNoticeParser();

	ParsedMessagePrivateMessagesNotice	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
