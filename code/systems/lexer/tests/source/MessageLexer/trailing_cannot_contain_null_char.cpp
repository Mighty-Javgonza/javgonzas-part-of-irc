#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa";
	str[1] = '\0';
	try {
		lexer.validateTrailingString(str);
	} catch (MessageLexer::TrailingContainsInvalidCharacterException) {
		return (0);
	}
	return (-1);
}
