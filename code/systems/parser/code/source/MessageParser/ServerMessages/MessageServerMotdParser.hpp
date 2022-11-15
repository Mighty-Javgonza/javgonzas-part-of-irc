class MessageServerMotdParser;class MessageServerMotdParser;

#ifndef MESSAGESERVERMOTDPARSER_HPP
# define MESSAGESERVERMOTDPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerMotd.hpp"

class MessageServerMotdParser : public MessageParser {

public:
	MessageServerMotdParser();
	~MessageServerMotdParser();

	ParsedMessageServerMotd	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif

#ifndef MESSAGESERVERMOTDPARSER_HPP
# define MESSAGESERVERMOTDPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ServerMessages/ParsedMessageServerMotd.hpp"

class MessageServerMotdParser : public MessageParser {

public:
	MessageServerMotdParser();
	~MessageServerMotdParser();

	ParsedMessageServerMotd	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
