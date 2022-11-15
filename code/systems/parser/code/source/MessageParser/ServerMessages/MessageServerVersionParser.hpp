class MessageServerVersionParser;

#ifndef MESSAGESERVERVERSIONPARSER_HPP
# define MESSAGESERVERVERSIONPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerVersion.hpp"

class MessageServerVersionParser : public MessageParser {

public:
	MessageServerVersionParser();
	~MessageServerVersionParser();

	ParsedMessageServerVersion	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
