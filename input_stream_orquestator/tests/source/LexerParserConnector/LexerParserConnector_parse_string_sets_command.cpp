#include "../tests.hpp"

int main()
{
	LexerParserConnector	parser;
	ParsedMessage	*result;

	result = parser.parse_string("QUIT");

	if (result->command != "QUIT")
		return (-1);
	return (0);
}
