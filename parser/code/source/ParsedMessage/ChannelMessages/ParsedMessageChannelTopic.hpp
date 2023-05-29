class ParsedMessageChannelTopic;

#ifndef PARSEDMESSAGECHANNELTOPIC_HPP
# define PARSEDMESSAGECHANNELTOPIC_HPP

# include "../ParsedMessage.hpp"
# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageChannelTopic : public ParsedMessage {

public:
	ParsedMessageChannelTopic();
	~ParsedMessageChannelTopic();

	channel_parameter	channel;
	bool				has_topic;
	std::string			topic;

};

#endif
