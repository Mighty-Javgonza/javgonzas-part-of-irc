class MessageChannelNamesParser;

#ifndef MESSAGECHANNELNAMESPARSER_HPP
# define MESSAGECHANNELNAMESPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelNames.hpp"

class MessageChannelNamesParser : public MessageParser {

public:
	MessageChannelNamesParser();
	~MessageChannelNamesParser();

	ParsedMessageChannelNames   *specific_message;

protected:
    void parse_specific_part();
    void create_specific_message();

};

#endif
