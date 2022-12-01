#include "../tests.hpp"

int main()
{
	MessageUserWhoParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("hello");
	parser.lexedMessage.parameters.push_back("o");
	parser.parse_specific_part();
	if (parser.specific_message->just_operators != true)
		return (-1);
	return (0);
}
