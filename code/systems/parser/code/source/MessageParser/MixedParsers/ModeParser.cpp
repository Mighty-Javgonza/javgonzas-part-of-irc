#include "ModeParser.hpp"
#include "../MessageParameterValidator.hpp"

ModeParser::ModeParser()
{
	is_channel = false;
}

ModeParser::~ModeParser()
{

}

void	ModeParser::parse_specific_part(void)
{
	if (is_channel) {
		MessageChannelModeParser::parse_specific_part();
	} else {
		MessageConnectionModeParser::parse_specific_part();
	}
}

void	ModeParser::create_specific_message(void)
{
	if (lexedMessage.parameters.size() < 1)
		throw MessageParser::needMoreParamsException;
	try {
		MessageParameterValidator::validate_nickname(lexedMessage.parameters[0]);
		in_progress_message = MessageConnectionModeParser::specific_message;
		MessageConnectionModeParser::create_specific_message();
		is_channel = false;
	} catch (MessageParameterValidator::ErroneousNicknameException &e) {
		is_channel = true;
		in_progress_message = MessageChannelModeParser::specific_message;
		MessageChannelModeParser::create_specific_message();
	}
	specific_message = in_progress_message;
}
