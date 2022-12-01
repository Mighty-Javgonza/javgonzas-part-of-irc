#include "../tests.hpp"

int main()
{
	MessageUserWhoisParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("127.0.0.1");
	parser.lexedMessage.parameters.push_back("aaa,bbb");
	parser.parse_specific_part();
	if (parser.specific_message->mask_list.masks[0] != "aaa")
		return (-1);
	if (parser.specific_message->has_target != true)
		return (-1);
	if (parser.specific_message->target.servername != "127.0.0.1")
		return (-1);
	return (0);
}
