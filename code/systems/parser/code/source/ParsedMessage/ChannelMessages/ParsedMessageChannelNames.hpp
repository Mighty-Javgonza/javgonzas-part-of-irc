class ParsedMessageChannelNames;

#ifndef PARSEDMESSAGECHANNELNAMES_HPP
# define PARSEDMESSAGECHANNELNAMES_HPP

#include "../../MessageParser/MessageParameterCommonParser.hpp"
#include "../ParsedMessage.hpp"

class ParsedMessageChannelNames : public ParsedMessage{

public:
	ParsedMessageChannelNames();
	~ParsedMessageChannelNames();

	channel_list_parameter	channel_list;
	std::string	target;
	bool	has_target;

};

#endif
