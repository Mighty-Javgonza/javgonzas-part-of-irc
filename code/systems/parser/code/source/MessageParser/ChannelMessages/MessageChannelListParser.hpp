class MessageChannelListParser;

#ifndef MESSAGECHANNELLISTPARSER_HPP
# define MESSAGECHANNELLISTPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelList.hpp"

class MessageChannelListParser : public MessageParser {

public:
	MessageChannelListParser();
	~MessageChannelListParser();

	ParsedMessageChannelList	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
