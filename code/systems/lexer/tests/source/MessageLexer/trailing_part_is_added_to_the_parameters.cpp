#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	msg;

	msg = lexer.lex(":hola USER abc def ghi :jkl mno");
	if (msg.parameters[3] != "jkl mno")
	return (0);
}
