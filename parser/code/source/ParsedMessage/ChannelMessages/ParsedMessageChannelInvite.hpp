class ParsedMessageChannelInvite;

#ifndef PARSEDMESSAGECHANNELINVITE_HPP
# define PARSEDMESSAGECHANNELINVITE_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageChannelInvite : public ParsedMessage {

public:
	ParsedMessageChannelInvite();
	~ParsedMessageChannelInvite();

	std::string	nickname;
	channel_parameter	channel;


};

#endif
