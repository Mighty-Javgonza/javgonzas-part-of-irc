class MessageUserPongParser;

#ifndef MESSAGEUSERPONGPARSER_HPP
# define MESSAGEUSERPONGPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserPong.hpp"

class MessageUserPongParser : public MessageParser {

public:
	MessageUserPongParser();
	~MessageUserPongParser();

	ParsedMessageUserPong	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
