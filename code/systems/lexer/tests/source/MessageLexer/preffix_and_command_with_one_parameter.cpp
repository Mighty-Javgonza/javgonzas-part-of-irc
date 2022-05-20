#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;

	result = lexer.lex(":zzz aaa bbb");
	if (result.parameters[0] != "bbb")
		return (-1);
	return (0);
}