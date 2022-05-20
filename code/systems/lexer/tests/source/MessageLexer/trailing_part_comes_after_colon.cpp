#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	result = lexer.lex(":zzz aaa ooo iii :bbbb");
	if (result.getTrailing() != "bbbb")
		return (-1);
	return (0);
}
