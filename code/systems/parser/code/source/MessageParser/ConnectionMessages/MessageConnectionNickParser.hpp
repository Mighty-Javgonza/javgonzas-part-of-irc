class MessageConnectionNickParser;

#ifndef MESSAGECONNECTIONNICKPARSER_HPP
# define MESSAGECONNECTIONNICKPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionNick.hpp"

class MessageConnectionNickParser : public MessageParser {

public:
	MessageConnectionNickParser();
	~MessageConnectionNickParser();

	ParsedMessageConnectionNick	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
