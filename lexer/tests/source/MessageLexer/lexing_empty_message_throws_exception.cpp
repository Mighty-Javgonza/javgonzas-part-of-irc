#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	try {
		result = lexer.lex("");
	} catch (MessageLexer::MissingCommandException) {
		return (0);
	}
	return (-1);
}
