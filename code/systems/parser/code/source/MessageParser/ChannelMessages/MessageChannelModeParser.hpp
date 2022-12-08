class MessageChannelModeParser;

#ifndef MESSAGECHANNELMODEPARSER_HPP
# define MESSAGECHANNELMODEPARSER_HPP

# include "../MessageParser.hpp"

# include "../../ParsedMessage/ChannelMessages/ParsedMessageChannelMode.hpp"

# define VALID_MODE_FLAGS "OovaimnqpsrtklbeI"
# define MODE_FLAGS_WITH_NO_PARAMS "Oovaimnqpsrt"
# define MODE_FLAGS_WITH_PARAMS "klbeI"

class MessageChannelModeParser : public MessageParser {

public:
	MessageChannelModeParser();
	~MessageChannelModeParser();

	ParsedMessageChannelMode	*specific_message;
	typedef	ParsedMessageChannelMode::channel_mode_flag	channel_mode_flag;

protected:
	void	parse_specific_part();
	void	create_specific_message();

	bool	is_valid_mode_flag(char flag);
	channel_mode_flag	set_needs_parameter(channel_mode_flag &chanflag);
	void	parse_flag_list(std::string str);
	void	push_flag_to_list(char flag, int action);

};

#endif
