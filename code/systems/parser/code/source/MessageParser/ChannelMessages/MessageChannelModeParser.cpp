#include "MessageChannelModeParser.hpp"

typedef	ParsedMessageChannelMode::channel_mode_flag	channel_mode_flag;

MessageChannelModeParser::MessageChannelModeParser()
{

}

MessageChannelModeParser::~MessageChannelModeParser()
{

}

void	MessageChannelModeParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->channel = MessageParameterCommonParser::parse_channel(lexedMessage.parameters[0]);
	if (lexedMessage.parameters.size() > 1)
		parse_flag_list(lexedMessage.parameters[1]);

	size_t	flag_index = 0;
	for (size_t i = 2; i < lexedMessage.parameters.size(); i++)
	{
		while (flag_index < specific_message->flags.size() && specific_message->flags[flag_index].needs_parameter == false)
			flag_index++;
		if (flag_index != specific_message->flags.size())
		{
			specific_message->flags[flag_index].parameter = lexedMessage.parameters[i];
			flag_index++;
		}
	}
}

void	MessageChannelModeParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelMode();
	in_progress_message = specific_message;
}

bool	MessageChannelModeParser::is_valid_mode_flag(char flag)
{
	std::string	valid_flags = VALID_MODE_FLAGS;

	for (size_t i = 0; i < valid_flags.length(); i++)
		if (flag == valid_flags[i])
			return (true);
	return (false);
}

channel_mode_flag	MessageChannelModeParser::set_needs_parameter(channel_mode_flag &chanflag)
{
	std::string	mode_flags_no_params = MODE_FLAGS_WITH_NO_PARAMS;

	chanflag.needs_parameter = (mode_flags_no_params.find(chanflag.flag) == std::string::npos);
	return (chanflag);
}

void	MessageChannelModeParser::parse_flag_list(std::string str)
{
	int	current_action;
	char	c;

	for (size_t i = 0; i < str.length(); i++)
	{
		c = str[i];
		if (is_valid_mode_flag(c))
			push_flag_to_list(c, current_action);
		else if (c == '+')
			current_action = CHANNEL_MODE_FLAG_ACTION_ADD;
		else if (c == '-')
			current_action = CHANNEL_MODE_FLAG_ACTION_REMOVE;
	}
}

void	MessageChannelModeParser::push_flag_to_list(char flag, int action)
{
		channel_mode_flag	chanflag;

		chanflag.flag = flag;
		set_needs_parameter(chanflag);
		chanflag.action = action;
		specific_message->flags.push_back(chanflag);
}
