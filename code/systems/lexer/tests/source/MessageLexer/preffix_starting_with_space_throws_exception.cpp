#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	try {
		result = lexer.lex(": aaa");
	} catch (MessageLexer::PreffixStartsWithSpaceException) {
		return (0);
	}
	return (-1);
}
