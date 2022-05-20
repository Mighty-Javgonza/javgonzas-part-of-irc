#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;
	std::string		str;

	str = "aa3";
	try {
		lexer.validateCommandString(str);
	} catch (MessageLexer::LetterCommandContainsNonLetterException) {
		return (0);
	}
	return (-1);
}
