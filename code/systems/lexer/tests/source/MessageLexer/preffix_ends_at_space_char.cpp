#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;

	lexer.setAnalysisString(":aaa ");
	lexer.setMessagePreffixIfItExists();
	if (lexer.in_progress_message.getPreffix() != "aaa")
		return (-1);
	lexer.setAnalysisString(":vvvvv bbb");
	lexer.setMessagePreffixIfItExists();
	if (lexer.in_progress_message.getPreffix() != "vvvvv")
		return (-1);
	return (0);
}
