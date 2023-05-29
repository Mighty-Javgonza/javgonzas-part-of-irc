class ParsedMessageChannelMode;

#ifndef PARSEDMESSAGECHANNELMODE_HPP
# define PARSEDMESSAGECHANNELMODE_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

# define CHANNEL_MODE_FLAG_ACTION_ADD 1
# define CHANNEL_MODE_FLAG_ACTION_REMOVE 2

class ParsedMessageChannelMode : public ParsedMessage {

public:
	ParsedMessageChannelMode();
	~ParsedMessageChannelMode();

	channel_parameter	channel;

	typedef struct	s_channel_mode_flag {
		char		flag;
		bool		needs_parameter;
		std::string	parameter;
		int			action;
	}				channel_mode_flag;

	bool intends_to_change_modes;
	std::vector<channel_mode_flag> flags;
};

#endif
