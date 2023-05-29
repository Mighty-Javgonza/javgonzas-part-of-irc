class MessageConnectionModeParser;

#ifndef MESSAGECONNECTIONMODEPARSER_HPP
# define MESSAGECONNECTIONMODEPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ConnectionMessages/ParsedMessageConnectionMode.hpp"
# include "../MessageParameterValidator.hpp"

class MessageConnectionModeParser : virtual public MessageParser {

public:
	MessageConnectionModeParser();
	~MessageConnectionModeParser();

	ParsedMessageConnectionMode	*specific_message;
	void	parse_specific_part();
	void	create_specific_message();

protected:

private:
	void	add_mode(char mode_name);
	void	remove_mode(char mode_name);
	void	parse_modes();

};

#endif
