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

bool	MessageParameterValidator::is_special_char(char c)
{
	return ((c >= 0x5b && c <= 0x60) || (c >= 0x7B && c <= 0x7D));
}

MessageParameterValidator::ErroneousNicknameException MessageParameterValidator::erroneousNicknameException;
