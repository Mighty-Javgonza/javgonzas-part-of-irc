#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "123 aaaa";
	str[5] = '\0';
	try {
		lexer.lex(str);
	} catch (MessageLexer::ParameterContainsInvalidCharacterException) {
		return (0);
	}
	return (-1);
}
