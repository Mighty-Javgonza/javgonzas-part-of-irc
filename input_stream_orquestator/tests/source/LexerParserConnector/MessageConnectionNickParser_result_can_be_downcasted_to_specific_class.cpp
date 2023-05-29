#include "../tests.hpp"

int main()
{
	LexerParserConnector	parser;
	ParsedMessage	*result;
	ParsedMessageConnectionNick	*readable_result;

	result = parser.parse_string("NICK patata turut"); //Apparently just one parameter passes test without doing the thing tested
	readable_result = static_cast<ParsedMessageConnectionNick *>(result);
	if (readable_result->nickname != "patata")
		return (-1);
	return (0);
}
