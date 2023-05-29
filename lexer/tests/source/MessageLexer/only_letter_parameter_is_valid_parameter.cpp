#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa";
	lexer.validateParameterString(str);
	return (0);
}
