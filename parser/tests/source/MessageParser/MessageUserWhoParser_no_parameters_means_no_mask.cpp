#include "../tests.hpp"

int main()
{
	MessageUserWhoParser	parser;

	parser.create_specific_message();
	parser.parse_specific_part();
	if (parser.specific_message->has_mask != false)
		return (-1);
	return (0);
}
