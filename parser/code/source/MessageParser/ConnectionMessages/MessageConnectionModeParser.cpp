#include "MessageConnectionModeParser.hpp"

MessageConnectionModeParser::MessageConnectionModeParser()
{
}

MessageConnectionModeParser::~MessageConnectionModeParser()
{

}

void	MessageConnectionModeParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() < 1)
		throw (needMoreParamsException);
	MessageParameterValidator::validate_nickname(lexedMessage.parameters[0]);
	specific_message->nickname = lexedMessage.parameters[0];
	if (lexedMessage.parameters.size() < 2)
	{
		specific_message->intends_to_change_modes = false;
		return ;
	}
	else
	{
		specific_message->intends_to_change_modes = true;
		parse_modes();
	}
}

void	MessageConnectionModeParser::parse_modes()
{
	std::string	&mode_str = lexedMessage.parameters[1];

	bool	state;

	if (mode_str[0] == '+')
		state = 0;
	else if (mode_str[0] == '-')
		state = 1;
	else
		return ;

	for (size_t i = 1; i < mode_str.length(); i++)
	{
		if (mode_str[i] == '+')
			state = 0;
		else if (mode_str[i] == '-')
			state = 1;
		else if (state == 0)
			add_mode(mode_str[i]);
		else
			remove_mode(mode_str[i]);
	}
}

void	MessageConnectionModeParser::add_mode(char mode_name)
{
	if (mode_name == 'a')
		specific_message->mode_a = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 'i')
		specific_message->mode_i = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 'w')
		specific_message->mode_w = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 'r')
		specific_message->mode_r = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 'o')
		specific_message->mode_o = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 'O')
		specific_message->mode_O = ParsedMessageConnectionMode::ADD_MODE;
	if (mode_name == 's')
		specific_message->mode_s = ParsedMessageConnectionMode::ADD_MODE;
}

void	MessageConnectionModeParser::remove_mode(char mode_name)
{
	if (mode_name == 'a')
		specific_message->mode_a = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 'i')
		specific_message->mode_i = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 'w')
		specific_message->mode_w = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 'r')
		specific_message->mode_r = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 'o')
		specific_message->mode_o = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 'O')
		specific_message->mode_O = ParsedMessageConnectionMode::REMOVE_MODE;
	if (mode_name == 's')
		specific_message->mode_s = ParsedMessageConnectionMode::REMOVE_MODE;
}

void	MessageConnectionModeParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionMode();
	in_progress_message = specific_message;
}
