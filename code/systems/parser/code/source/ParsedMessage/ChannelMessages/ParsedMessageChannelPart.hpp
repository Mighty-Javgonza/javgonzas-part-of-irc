class ParsedMessageChannelPart;

#ifndef PARSEDMESSAGECHANNELPART_HPP
# define PARSEDMESSAGECHANNELPART_HPP

# include "../../MessageParser/MessageParameterCommonParser.hpp"
# include "../ParsedMessage.hpp"

class ParsedMessageChannelPart : public ParsedMessage{

public:
	ParsedMessageChannelPart();
	~ParsedMessageChannelPart();

	channel_list_parameter	channel_list;
	bool	has_part_message;
	std::string	part_message;
};

#endif
