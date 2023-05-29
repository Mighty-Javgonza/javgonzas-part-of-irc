#include "../tests.hpp"

int main()
{
	MessageChannelJoinParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("0");
	parser.parse_specific_part();
	if (parser.specific_message->leave_all_channels != true)
		return (-1);
	return (0);
}
