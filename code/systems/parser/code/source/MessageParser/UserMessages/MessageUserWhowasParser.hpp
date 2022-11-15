class MessageUserWhowasParser;

#ifndef MESSAGEUSERWHOWASPARSER_HPP
# define MESSAGEUSERWHOWASPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserWhowas.hpp"

class MessageUserWhowasParser : public MessageParser {

public:
	MessageUserWhowasParser();
	~MessageUserWhowasParser();

	ParsedMessageUserWhowas	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
