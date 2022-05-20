#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;

	result = lexer.lex("aaa 1111 2222 3333 4444 5555 6666 7777 8888 9999 0010 0011 0012 0013 0014 :0015");
	if (result.getTrailing() != "0015")	
		return (-1);
	return (0);
}
