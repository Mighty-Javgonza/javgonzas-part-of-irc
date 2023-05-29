class MessageServerTimeParser;

#ifndef MESSAGESERVERTIMEPARSER_HPP
# define MESSAGESERVERTIMEPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerTime.hpp"

class MessageServerTimeParser : public MessageParser {

public:
	MessageServerTimeParser();
	~MessageServerTimeParser();

	ParsedMessageServerTime	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
