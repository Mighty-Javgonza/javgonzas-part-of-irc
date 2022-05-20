#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	result = lexer.lex(":zzz aaa bbb ccc");
	if (result.parameters[1] != "ccc")
		return (-1);
	return (0);
}
