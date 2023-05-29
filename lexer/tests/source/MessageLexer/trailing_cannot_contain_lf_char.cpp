#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa";
	str[1] = '\10';
	try {
		lexer.validateTrailingString(str);
	} catch (MessageLexer::TrailingContainsInvalidCharacterException) {
		return (0);
	}
	return (-1);
}
