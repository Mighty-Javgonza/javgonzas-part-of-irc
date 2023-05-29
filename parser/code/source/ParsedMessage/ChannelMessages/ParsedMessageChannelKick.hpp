class ParsedMessageChannelKick;

#ifndef PARSEDMESSAGECHANNELKICK_HPP
# define PARSEDMESSAGECHANNELKICK_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageChannelKick : public ParsedMessage {

public:
	ParsedMessageChannelKick();
	~ParsedMessageChannelKick();
	
	channel_list_parameter	channel_list;
	user_list_parameter	user_list;
	bool	has_comment;
	std::string	comment;

};

#endif
