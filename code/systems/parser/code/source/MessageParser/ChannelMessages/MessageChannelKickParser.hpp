class MessageChannelKickParser;

#ifndef MESSAGECHANNELKICKPARSER_HPP
# define MESSAGECHANNELKICKPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelKick.hpp"

class MessageChannelKickParser : public MessageParser {

public:
	MessageChannelKickParser();
	~MessageChannelKickParser();

	ParsedMessageChannelKick	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
