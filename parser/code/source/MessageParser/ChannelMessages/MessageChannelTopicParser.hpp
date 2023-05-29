class MessageChannelTopicParser;

#ifndef MESSAGECHANNELTOPICPARSER_HPP
# define MESSAGECHANNELTOPICPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelTopic.hpp"

class MessageChannelTopicParser : public MessageParser {

public:
	MessageChannelTopicParser();
	~MessageChannelTopicParser();

	ParsedMessageChannelTopic	*specific_message;

protected:
	void parse_specific_part();
	void create_specific_message();

};

#endif
