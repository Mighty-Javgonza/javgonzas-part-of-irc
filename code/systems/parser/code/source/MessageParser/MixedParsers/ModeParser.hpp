class ModeParser;

#ifndef MODEPARSER_HPP
# define MODEPARSER_HPP

# include "../MessageParser.hpp"

# include "../ConnectionMessages/MessageConnectionModeParser.hpp"
# include "../ChannelMessages/MessageChannelModeParser.hpp"

# include "../MessageParameterValidator.hpp"

class ModeParser : public MessageChannelModeParser, MessageConnectionModeParser {

public:
	ModeParser();
	~ModeParser();

	ParsedMessage	*specific_message;


protected:
	void	parse_specific_part();
	void	create_specific_message();

private:
	bool is_channel;

};

#endif
