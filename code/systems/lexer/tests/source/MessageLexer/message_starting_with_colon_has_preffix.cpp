#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	lexer.setAnalysisString(":aaa");
	lexer.setMessagePreffixIfItExists();
	result = lexer.in_progress_message;
	if (result.checkHasPreffix() != true)
		return (-1);
	return (0);
}
