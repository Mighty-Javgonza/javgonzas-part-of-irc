class MessageServerStatsParser;

#ifndef MESSAGESERVERSTATSPARSER_HPP
# define MESSAGESERVERSTATSPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerStats.hpp"

class MessageServerStatsParser : public MessageParser {

public:
	MessageServerStatsParser();
	~MessageServerStatsParser();

	ParsedMessageServerStats	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
