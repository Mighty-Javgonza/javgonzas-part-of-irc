#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa : bbbb";
	str[7] = '\0';
	try {
		lexer.lex(str);
	} catch (MessageLexer::TrailingContainsInvalidCharacterException) {
		return (0);
	}
	return (-1);
}
