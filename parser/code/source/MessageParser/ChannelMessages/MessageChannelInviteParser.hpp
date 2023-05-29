class MessageChannelInviteParser;

#ifndef MESSAGECHANNELINVITEPARSER_HPP
# define MESSAGECHANNELINVITEPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelInvite.hpp"

class MessageChannelInviteParser : public MessageParser {

public:
	MessageChannelInviteParser();
	~MessageChannelInviteParser();

	ParsedMessageChannelInvite	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
