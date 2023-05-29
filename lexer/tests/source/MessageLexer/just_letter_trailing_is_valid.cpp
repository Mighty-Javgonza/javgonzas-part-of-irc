#include "../tests.hpp"

int main()
{
	MessageLexer	lexer;
	std::string		str;

	str = "aaa";
	lexer.validateTrailingString(str);
	return (0);
}
