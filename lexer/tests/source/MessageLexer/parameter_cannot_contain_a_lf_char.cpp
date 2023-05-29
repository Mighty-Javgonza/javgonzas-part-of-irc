#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa";
	str[1] = '\10';
	try {
		lexer.validateParameterString(str);
	} catch (MessageLexer::ParameterContainsInvalidCharacterException) {
		return (0);
	}
	return (-1);
}
