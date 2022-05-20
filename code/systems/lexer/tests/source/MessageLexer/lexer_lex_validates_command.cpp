#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;
	LexedMessage	result;

	try {
		result = lexer.lex("12a");
	} catch (MessageLexer::NumericCommandContainNonDigitsException)
	{
		return (0);
	}
	return (-1);
}
