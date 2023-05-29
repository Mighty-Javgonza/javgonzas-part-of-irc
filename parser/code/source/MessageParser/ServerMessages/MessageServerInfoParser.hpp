class MessageServerInfoParser;

#ifndef MESSAGESERVERINFOPARSER_HPP
# define MESSAGESERVERINFOPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerInfo.hpp"

class MessageServerInfoParser : public MessageParser {

public:
	MessageServerInfoParser();
	~MessageServerInfoParser();

	ParsedMessageServerInfo	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
