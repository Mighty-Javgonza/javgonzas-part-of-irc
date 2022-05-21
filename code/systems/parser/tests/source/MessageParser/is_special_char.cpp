#include "../tests.hpp"

int main()
{
	if (MessageParameterValidator::is_special_char('a'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('['))
		return (-1);
	if (!MessageParameterValidator::is_special_char(']'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('\\'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('`'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('_'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('^'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('{'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('|'))
		return (-1);
	if (!MessageParameterValidator::is_special_char('}'))
		return (-1);
	return (0);
}
