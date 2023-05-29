class MessageUserErrorParser;

#ifndef MESSAGEUSERERRORPARSER_HPP
# define MESSAGEUSERERRORPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserError.hpp"

class MessageUserErrorParser : public MessageParser {

public:
	MessageUserErrorParser();
	~MessageUserErrorParser();

	ParsedMessageUserError	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
