#include "../tests.hpp"

int main()
{
	MessageChannelJoinParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#gogogo");
	parser.lexedMessage.parameters.push_back("abc,def");
	parser.parse_specific_part();
	if (parser.specific_message->has_key_list != true)
		return (-1);
	if (parser.specific_message->key_list.keys[1] != "def")
		return (-1);
	return (0);
}
