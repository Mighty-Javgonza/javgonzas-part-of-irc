class MessageConnectionQuitParser;

#ifndef MESSAGECONNECTIONQUITPARSER_HPP
# define MESSAGECONNECTIONQUITPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionQuit.hpp"

class MessageConnectionQuitParser : public MessageParser{

public:
	MessageConnectionQuitParser();
	~MessageConnectionQuitParser();

	ParsedMessageConnectionQuit	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
