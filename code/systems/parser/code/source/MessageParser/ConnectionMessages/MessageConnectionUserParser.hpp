class MessageConnectionUserParser;

#ifndef MESSAGECONNECTIONUSERPARSER_HPP
# define MESSAGECONNECTIONUSERPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionUser.hpp"

class MessageConnectionUserParser : public MessageParser{

public:
	MessageConnectionUserParser();
	~MessageConnectionUserParser();

	ParsedMessageConnectionUser	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
