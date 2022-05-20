#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;

	lexer.setAnalysisString(":aaa");
	lexer.setMessagePreffixIfItExists();
	result = lexer.in_progress_message;
	if (result.checkHasPreffix() != true)
		return (-1);
	if (result.getPreffix() != "aaa")
		return (-1);
	return (0);
}
