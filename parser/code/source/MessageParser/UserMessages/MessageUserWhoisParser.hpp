class MessageUserWhoisParser;

#ifndef MESSAGEUSERWHOISPARSER_HPP
# define MESSAGEUSERWHOISPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserWhois.hpp"

class MessageUserWhoisParser : public MessageParser {

public:
	MessageUserWhoisParser();
	~MessageUserWhoisParser();

	ParsedMessageUserWhois	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
