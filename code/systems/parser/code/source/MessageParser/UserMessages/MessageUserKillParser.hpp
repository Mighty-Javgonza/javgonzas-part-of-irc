class MessageUserKillParser;

#ifndef MESSAGEUSERKILLPARSER_HPP
# define MESSAGEUSERKILLPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/UserMessages/ParsedMessageUserKill.hpp"

class MessageUserKillParser : public MessageParser {

public:
	MessageUserKillParser();
	~MessageUserKillParser();

	ParsedMessageUserKill	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
