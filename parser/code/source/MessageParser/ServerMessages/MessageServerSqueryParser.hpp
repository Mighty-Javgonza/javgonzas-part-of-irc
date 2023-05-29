class MessageServerSqueryParser;

#ifndef MESSAGESERVERSQUERYPARSER_HPP
# define MESSAGESERVERSQUERYPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerSquery.hpp"

class MessageServerSqueryParser : public MessageParser {

public:
	MessageServerSqueryParser();
	~MessageServerSqueryParser();

	ParsedMessageServerSquery	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
