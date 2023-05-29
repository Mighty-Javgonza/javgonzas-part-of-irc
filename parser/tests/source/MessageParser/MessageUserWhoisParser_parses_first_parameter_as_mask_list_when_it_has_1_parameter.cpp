#include "../tests.hpp"

int main()
{
	MessageUserWhoisParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("aaa,bbb");
	parser.parse_specific_part();
	if (parser.specific_message->mask_list.masks[0] != "aaa")
		return (-1);
	return (0);
}
