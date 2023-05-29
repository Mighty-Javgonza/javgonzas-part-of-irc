#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	LexedMessage	result;

	lexer.setAnalysisString("");
	lexer.setMessagePreffixIfItExists();
	result = lexer.in_progress_message;
	if (result.checkHasPreffix() != false)
		return (-1);
	return (0);
}
