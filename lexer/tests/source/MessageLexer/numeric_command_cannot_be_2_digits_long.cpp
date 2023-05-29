#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "12";
	try {
		lexer.validateCommandString(str);
	} catch (MessageLexer::NumericCommandIsNotThreeDigitsLongException)
	{
		return (0);
	}
	return (-1);
}
