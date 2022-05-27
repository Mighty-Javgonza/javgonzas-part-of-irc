#include "MessageParameterCommonParser.hpp"


MessageParameterCommonParser::MessageParameterCommonParser()
{

}

MessageParameterCommonParser::~MessageParameterCommonParser()
{

}

channel_parameter	MessageParameterCommonParser::parse_channel(std::string str)
{
	channel_parameter	channel;
	size_t				analyzed_chars;

	if (str.length() > 50 || str.length() < 2)
		throw (MessageParameterValidator::erroneousChannelException);
	analyzed_chars = 0;
	if (str[0] == '#' || str[0] == '+' || str[0] == '&')
	{
		channel.type = str[0];
		analyzed_chars = 1;
	}
	else if (str[0] == '!')
	{
		parse_channel_id_part(str, channel);
		analyzed_chars = 6;
	}
	else
		throw (MessageParameterValidator::erroneousChannelException);

	size_t	mask_separator;
	mask_separator = str.find_first_of(':', analyzed_chars);
	if (mask_separator != std::string::npos)
	{
		channel.mask = str.substr(mask_separator + 1, str.length() - (mask_separator + 1));
		channel.name = str.substr(analyzed_chars, mask_separator - 1);
	}
	else
	{
		channel.name = str.substr(analyzed_chars, str.length() - analyzed_chars);
	}
	return (channel);
}

void	MessageParameterCommonParser::parse_channel_id_part(std::string str, channel_parameter &channel)
{
		if (str.length() < 6)
			throw (MessageParameterValidator::erroneousChannelidException);
		std::string	channelid;

		channelid = str.substr(1, 5);
		MessageParameterValidator::validate_channelid(channelid);
		channel.id = channelid;
}

msgto_parameter	MessageParameterCommonParser::parse_msgto(std::string str)
{
	msgto_parameter	msgto;

	if (str.find_first_of('@') == std::string::npos)
	{
		msgto.is_channel = true;
		msgto.channel = parse_channel(str);
	}
	else
	{
		msgto.is_channel = false;

		size_t	host_marker;
		size_t	server_marker;

		server_marker = str.find_first_of('@');
		if (server_marker == std::string::npos)
			throw (MessageParameterValidator::erroneousMsgtoException);
		host_marker = str.find_first_of('%');
		if (host_marker != std::string::npos)
		{
			msgto.has_host = true;
			msgto.user = str.substr(0, host_marker);
			msgto.host = str.substr(host_marker + 1, server_marker - (host_marker + 1));
			msgto.server = str.substr(server_marker + 1, str.length() - (server_marker + 1));
			MessageParameterValidator::validate_host(msgto.host);
		}
		else
		{
			msgto.has_host = false;
			msgto.user = str.substr(0, server_marker);
			msgto.server = str.substr(server_marker + 1, str.length() - (server_marker + 1));
		}
		MessageParameterValidator::validate_user(msgto.user);
		MessageParameterValidator::validate_hostname(msgto.server);
	}
	return (msgto);
}
