class MessageConnectionPassParser;

#ifndef MESSAGECONNECTIONPASSPARSER_HPP
# define MESSAGECONNECTIONPASSPARSER_HPP

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionPass.hpp"
# include "../MessageParser.hpp"

class MessageConnectionPassParser : public MessageParser {

public:
	MessageConnectionPassParser();
	~MessageConnectionPassParser();

	ParsedMessageConnectionPass	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
