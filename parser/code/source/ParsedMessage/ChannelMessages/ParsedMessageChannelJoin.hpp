class ParsedMessageChannelJoin;

#ifndef PARSEDMESSAGECHANNELJOIN_HPP
# define PARSEDMESSAGECHANNELJOIN_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageChannelJoin : public ParsedMessage {

public:
	ParsedMessageChannelJoin();
	~ParsedMessageChannelJoin();

	bool	leave_all_channels;
	bool	has_channel_list;
	channel_list_parameter	channel_list;
	bool	has_key_list;
	key_list_parameter	key_list;

private:

};

#endif
