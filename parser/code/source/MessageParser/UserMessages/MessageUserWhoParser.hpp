class MessageUserWhoParser;

#ifndef MESSAGEUSERWHOPARSER_HPP
# define MESSAGEUSERWHOPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserWho.hpp"

class MessageUserWhoParser : public MessageParser {

public:
	MessageUserWhoParser();
	~MessageUserWhoParser();

	ParsedMessageUserWho	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
