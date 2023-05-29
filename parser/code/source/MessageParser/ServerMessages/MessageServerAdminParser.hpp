class MessageServerAdminParser;

#ifndef MESSAGESERVERADMINPARSER_HPP
# define MESSAGESERVERADMINPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerAdmin.hpp"

class MessageServerAdminParser : public MessageParser {

public:
	MessageServerAdminParser();
	~MessageServerAdminParser();

	ParsedMessageServerAdmin	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
