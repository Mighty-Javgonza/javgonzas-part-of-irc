#include "MessageChannelNamesParser.hpp"

MessageChannelNamesParser::MessageChannelNamesParser()
{

}

MessageChannelNamesParser::~MessageChannelNamesParser()
{

}

void    MessageChannelNamesParser::parse_specific_part()
{
	if	(lexedMessage.parameters.size() == 0)
		return ;
	std::string&	channels_parameter = lexedMessage.parameters[0];
	specific_message->channel_list = MessageParameterCommonParser::parse_channel_list(channels_parameter);

	if (lexedMessage.parameters.size() == 2)
	{
		MessageParameterValidator::validate_hostname(lexedMessage.parameters[1]);
		specific_message->has_target = true;
		specific_message->target = lexedMessage.parameters[1];
	}
}

void    MessageChannelNamesParser::create_specific_message(void)
{
    specific_message = new ParsedMessageChannelNames();
    in_progress_message = specific_message;
}
