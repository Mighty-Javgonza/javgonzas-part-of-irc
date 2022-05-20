#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	result = lexer.lex(":zzz aaa :bbbb");
	if (result.parameters.size() != 0)
		return (-1);
	return (0);
}
