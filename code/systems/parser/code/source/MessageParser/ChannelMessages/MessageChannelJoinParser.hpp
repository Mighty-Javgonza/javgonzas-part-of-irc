class MessageChannelJoinParser;

#ifndef MESSAGECHANNELJOINPARSER_HPP
# define MESSAGECHANNELJOINPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelJoin.hpp"

class MessageChannelJoinParser : public MessageParser {

public:
	MessageChannelJoinParser();
	~MessageChannelJoinParser();

	ParsedMessageChannelJoin	*specific_message;

protected:
	void	parse_specific_part();
	void	create_specific_message();

};

#endif
