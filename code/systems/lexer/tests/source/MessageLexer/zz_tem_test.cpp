#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	msg;

	msg = lexer.lex(":hola USER abc def ghi :sisisiisiiisisis");
	msg.printDebug();
	return (0);
}
