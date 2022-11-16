#include "MessageChannelListParser.hpp"


MessageChannelListParser::MessageChannelListParser()
{

}

MessageChannelListParser::~MessageChannelListParser()
{

}

void	MessageChannelListParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		specific_message->has_channels = false;
	else
	{
		specific_message->has_channels = true;
		specific_message->channel_list = MessageParameterCommonParser::parse_channel_list(lexedMessage.parameters[0]);
		if (lexedMessage.parameters.size() > 1)
		{
			specific_message->has_target = true;
			specific_message->target = lexedMessage.parameters[1];
		}
	}
}

void	MessageChannelListParser::create_specific_message()
{
	specific_message = new ParsedMessageChannelList();
	in_progress_message = specific_message;
}
