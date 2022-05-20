#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "123";
	lexer.validateCommandString(str);
	return (0);
}
