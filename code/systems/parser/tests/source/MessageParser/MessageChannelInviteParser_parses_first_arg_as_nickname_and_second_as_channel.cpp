#include "../tests.hpp"

int main()
{
	MessageChannelInviteParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("@nick");
	parser.lexedMessage.parameters.push_back("#chan");
	parser.parse_specific_part();
	if (parser.specific_message->nickname != "@nick")
		return (-1);
	if (parser.specific_message->channel.name != "chan")
		return (-1);
	return (0);
}
