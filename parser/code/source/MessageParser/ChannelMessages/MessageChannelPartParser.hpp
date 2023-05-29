class MessageChannelPartParser;

#ifndef MESSAGECHANNELPARTPARSER_HPP
# define MESSAGECHANNELPARTPARSER_HPP

# include "../MessageParser.hpp"
# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelPart.hpp"

class MessageChannelPartParser : public MessageParser{

public:
	MessageChannelPartParser();
	~MessageChannelPartParser();

	ParsedMessageChannelPart	*specific_message;

protected:
    void parse_specific_part();
    void create_specific_message();


};

#endif
