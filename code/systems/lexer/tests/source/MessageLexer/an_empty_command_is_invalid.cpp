#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	Message			result;
	std::string		str;

	str = "";
	try {
		lexer.validateCommandString(str);
	} catch (MessageLexer::EmptyCommandException) {
		return (0);
	}
	return (-1);
}
