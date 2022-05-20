#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	result = lexer.lex("aaa bbb");
	if (result.parameters[0] != "bbb")
		return (-1);
	return (0);
}
