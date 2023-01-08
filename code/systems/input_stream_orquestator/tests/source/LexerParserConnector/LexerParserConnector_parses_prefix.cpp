#include "../tests.hpp"

int main()
{
	LexerParserConnector	parser;
	ParsedMessage	*result;

	result = parser.parse_string(":127.0.0.1 QUIT");

	if (result->command != "QUIT")
		return (-1);
	if (result->preffix != "127.0.0.1")
		return (-1);
	return (0);
}
