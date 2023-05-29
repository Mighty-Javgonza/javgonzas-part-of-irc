#include "../tests.hpp"

int main()
{
	MessageUserErrorParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("HOIHOI");
	parser.parse_specific_part();
	if (parser.specific_message->error_message != "HOIHOI")
		return (-1);
	return (0);
}
