#include "MessageParameterValidator.hpp"

MessageParameterValidator::MessageParameterValidator()
{

}

MessageParameterValidator::~MessageParameterValidator()
{

}

void	MessageParameterValidator::validate_nickname(std::string str)
{
	if (str.length() < 1 || str.length() >= 10)
		throw (erroneousNicknameException);
	if (!std::isalpha(str[0]) && !is_special_char(str[0]))
		throw (erroneousNicknameException);
	for (size_t i = 1; i < str.length(); i++)
		if (!std::isalpha(str[i]) && !is_special_char(str[i]) && !std::isdigit(str[i]) && str[i] != '-')
			throw (erroneousNicknameException);
}

void	MessageParameterValidator::validate_user(std::string str)
{
	if (str.length() < 1 || str.length() >= 10)
		throw (erroneousUserStringException);
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '\0' || str[i] == '\r' || str[i] == '\n' || str[i] == ' ' || str[i] == '@')
			throw (erroneousUserStringException);
}

void	MessageParameterValidator::validate_chanstring(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '\0' || str[i] == '\7' || str[i] == '\r' || str[i] == '\n' || str[i] == ' ' || str[i] == ',' || str[i] == ':')
			throw (erroneousChanstringException);
}

void	MessageParameterValidator::validate_channelid(std::string str)
{
	if (str.length() != 5)
		throw (erroneousChannelidException);
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]) && ! std::isdigit(str[i]))
			throw (erroneousChannelidException);
}

void	MessageParameterValidator::validate_ipv4(std::string str)
{
	if (str.length() < 7 || str.length() > 15)
		throw (erroneousIP4Exception);

	size_t	analyzed_chars = 0;
	for (size_t i = 0; i < 3; i++)
	{
		size_t	j = 0;
		while (j < 3 && str[analyzed_chars] != '.')
		{
			if (!std::isdigit(str[analyzed_chars]))
				throw (erroneousIP4Exception);
			analyzed_chars++;
			j++;
		}
		if (str[analyzed_chars] != '.')
			throw (erroneousIP4Exception);
		analyzed_chars++;
	}
	size_t	j = 0;
	while (j < 3 && analyzed_chars < str.length())
	{
		if (!std::isdigit(str[analyzed_chars]))
			throw (erroneousIP4Exception);
		j++;
		analyzed_chars++;
	}
}

void	MessageParameterValidator::validate_ipv6(std::string str)
{
	if (str.length() < 15)
		throw (erroneousIP6Exception);
	
	if (str.find_first_of('.') != std::string::npos)
	{
		if (std::strncmp(str.c_str(), "0:0:0:0:0:0:", 12) == 0)
			validate_ipv4(&str[12]);
		else if (std::strncmp(str.c_str(), "0:0:0:0:0:FFFF:", 15) == 0)
			validate_ipv4(&str[15]);
		else
			throw (erroneousIP6Exception);
		return ;
	}


	size_t	analyzed_chars = 0;

	for (size_t j = 0; j < 7; j++)
	{
		while (is_hexdigit(str[analyzed_chars]) && analyzed_chars < str.length())
			analyzed_chars++;
		if (analyzed_chars == str.length() || str[analyzed_chars] != ':')
			throw (erroneousIP6Exception);
		analyzed_chars++;
	}
	while (is_hexdigit(str[analyzed_chars]) && analyzed_chars < str.length())
		analyzed_chars++;
	if (!is_hexdigit(str[analyzed_chars]))
		throw (erroneousIP6Exception);
}

void	MessageParameterValidator::validate_hostaddr(std::string str)
{
	if (str.find_first_of(':') != std::string::npos)
		validate_ipv6(str);
	else
		validate_ipv4(str);
}

void	MessageParameterValidator::validate_hostname(std::string str)
{
	std::string	working_str;
	size_t	analyzed_chars = 0;
	size_t	next_marker;

	if (str.length() > 63)
		throw (erroneousHostnameException);
	next_marker = str.find_first_of('.');
	while (next_marker != std::string::npos)
	{
		working_str = str.substr(analyzed_chars, next_marker - analyzed_chars);
		if (!is_shortname(working_str))
			throw (erroneousHostnameException);
		analyzed_chars = next_marker + 1;
		next_marker = str.find_first_of('.', analyzed_chars);
	}
	working_str = str.substr(analyzed_chars, str.length() - analyzed_chars);
	if (!is_shortname(working_str))
		throw (erroneousHostnameException);
}

void	MessageParameterValidator::validate_host(std::string str)
{
	//UFF un try catch para validar parseo es muy lento
	try {
		validate_hostname(str);
	} catch (ErroneousHostnameException)
	{
		try {
			validate_hostaddr(str);
		} catch (std::exception) {
			throw (erroneousHostException);
		}
	}
}

void	MessageParameterValidator::validate_key(std::string str)
{
	if (str.length() == 0 || str.length() > 23)
		throw (erroneousKeyException);
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (*it == '\x0' || *it == '\x09' || *it == '\x0A' || *it == '\x0B' || *it == '\x20')
			throw (erroneousKeyException);
}

void	MessageParameterValidator::validate_mask(std::string str)
{
	size_t	first_invalid_char = str.find('\0');

	if (first_invalid_char != std::string::npos)
		throw (erroneousMaskException);
}

bool	MessageParameterValidator::is_shortname(std::string str)
{
	if (str.length() < 1 && !std::isalpha(str[0]) && !std::isdigit(str[0]))
		return (false);
	for (size_t i = 1; i < str.length() - 1; i++)
		if (!std::isalpha(str[i]) && !std::isdigit(str[i]) && str[i] != '-')
			return (false);

	char	c;
	c = str[str.length() - 1];
	if (!std::isalpha(c) && !std::isdigit(c))
		return (false);
	return (true);
}

bool	MessageParameterValidator::is_special_char(char c)
{
	return ((c >= 0x5b && c <= 0x60) || (c >= 0x7B && c <= 0x7D));
}

bool	MessageParameterValidator::is_hexdigit(char c)
{
	return (std::isdigit(c) || (c >= 'A' && c <= 'F'));
}

MessageParameterValidator::ErroneousNicknameException MessageParameterValidator::erroneousNicknameException;
MessageParameterValidator::ErroneousUserStringException MessageParameterValidator::erroneousUserStringException;
MessageParameterValidator::ErroneousChanstringException MessageParameterValidator::erroneousChanstringException;
MessageParameterValidator::ErroneousChannelidException MessageParameterValidator::erroneousChannelidException;
MessageParameterValidator::ErroneousChannelException MessageParameterValidator::erroneousChannelException;
MessageParameterValidator::ErroneousIP4Exception MessageParameterValidator::erroneousIP4Exception;
MessageParameterValidator::ErroneousIP6Exception MessageParameterValidator::erroneousIP6Exception;
MessageParameterValidator::ErroneousHostnameException MessageParameterValidator::erroneousHostnameException;
MessageParameterValidator::ErroneousHostException MessageParameterValidator::erroneousHostException;
MessageParameterValidator::ErroneousMsgtoException MessageParameterValidator::erroneousMsgtoException;
MessageParameterValidator::ErroneousMsgtargetException MessageParameterValidator::erroneousMsgtargetException;
MessageParameterValidator::ErroneousTargetException MessageParameterValidator::erroneousTargetException;
MessageParameterValidator::ErroneousKeyException MessageParameterValidator::erroneousKeyException;
MessageParameterValidator::ErroneousQueryException MessageParameterValidator::erroneousQueryException;
MessageParameterValidator::ErroneousMaskException MessageParameterValidator::erroneousMaskException;
