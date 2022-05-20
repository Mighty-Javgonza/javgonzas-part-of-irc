#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	result = lexer.lex("dododo ");
	if (result.getCommand() != "dododo")
		return (-1);
	return (0);
}
