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
	size_t	host_marker;
	size_t	server_marker;
	size_t	user_marker;

	server_marker = str.find_first_of('@');
	user_marker = str.find_first_of('!');
	if (user_marker != std::string::npos)
	{
		msgto.is_nickname = true;
		msgto.has_host = true;
		host_marker = str.find_first_of('@');
		if (host_marker == std::string::npos)
			throw (MessageParameterValidator::erroneousMsgtoException);
		msgto.nickname = str.substr(0, user_marker);
		msgto.user = str.substr(user_marker + 1, host_marker - (user_marker + 1));
		msgto.host = str.substr(host_marker + 1, str.length() - (host_marker + 1));
		MessageParameterValidator::validate_nickname(msgto.nickname);
		MessageParameterValidator::validate_user(msgto.user);
		MessageParameterValidator::validate_host(msgto.host);
		return (msgto);
	}
	host_marker = str.find_first_of('%');
	if (server_marker == std::string::npos)
	{
		parse_msgto_without_servername(str, msgto);
		return (msgto);
	}
	msgto.has_server = true;
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
	return (msgto);
}

void MessageParameterCommonParser::parse_msgto_without_servername(std::string str, msgto_parameter &msgto)
{
	size_t	host_marker;

	host_marker = str.find_first_of('%');
	msgto.has_server = false;
	if (host_marker == std::string::npos)
	{
		try {
			msgto.channel = parse_channel(str);
		} catch (std::exception) {
			msgto.is_nickname = true;
			msgto.nickname = str;
			MessageParameterValidator::validate_nickname(msgto.nickname);
			return ;
		//	throw (MessageParameterValidator::erroneousMsgtoException);
		}
		msgto.is_channel = true;
	}
	msgto.has_host = true;
	msgto.user = str.substr(0, host_marker);
	msgto.host = str.substr(host_marker + 1, str.length() - (host_marker + 1));
	MessageParameterValidator::validate_user(msgto.user);
	MessageParameterValidator::validate_host(msgto.host);
}

msgtarget_parameter MessageParameterCommonParser::parse_msgtarget(std::string str)
{
	msgtarget_parameter msgtarget;
	std::string	current_msgto;
	size_t	next_msgto_marker;
	size_t	temp;
	size_t	analyzed_chars;

	if (str.length() == 0)
		throw (MessageParameterValidator::erroneousMsgtargetException);
	next_msgto_marker = 0;
	analyzed_chars = 0;
	while (true)
	{
		std::string	current_msgto;
		temp = str.find_first_of(',', next_msgto_marker);
		if (temp == std::string::npos)
		{
			current_msgto = str.substr(next_msgto_marker, str.length() - next_msgto_marker);
			msgtarget.targets.push_back(MessageParameterCommonParser::parse_msgto(current_msgto));
			return (msgtarget);
		}
		current_msgto = str.substr(next_msgto_marker, temp - (next_msgto_marker));
		next_msgto_marker = temp + 1;
		msgtarget.targets.push_back(MessageParameterCommonParser::parse_msgto(current_msgto));
	}
}
