class MessageConnectionOperParser;

#ifndef MESSAGECONNECTIONOPERPARSER_HPP
# define MESSAGECONNECTIONOPERPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionOper.hpp"

class MessageConnectionOperParser : public MessageParser{

public:
	MessageConnectionOperParser();
	~MessageConnectionOperParser();

	ParsedMessageConnectionOper	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
