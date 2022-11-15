class MessageUserPingParser;

#ifndef MESSAGEUSERPINGPARSER_HPP
# define MESSAGEUSERPINGPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserPing.hpp"

class MessageUserPingParser : public MessageParser {

public:
	MessageUserPingParser();
	~MessageUserPingParser();

	ParsedMessageUserPing	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
