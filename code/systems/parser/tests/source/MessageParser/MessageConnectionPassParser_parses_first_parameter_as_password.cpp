#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionPassParser	parser;
	ParsedMessageConnectionPass	*result;

	parser.lexedMessage.parameters.push_back("1234");
	parser.parse_specific_part();
	result = parser.specific_message;
	if (result->password != "1234")
		return (-1);
	return (0);
}
