#include "../tests.hpp"

int main()
{
	MessageUserWhoParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("hello");
	parser.parse_specific_part();
	if (parser.specific_message->has_mask != true)
		return (-1);
	if (parser.specific_message->mask != "hello")
		return (-1);
	return (0);
}
