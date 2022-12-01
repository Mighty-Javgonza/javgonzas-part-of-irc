#include "../tests.hpp"

int main()
{
	MessageServerTimeParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("127.0.0.1");
	parser.parse_specific_part();
	if (parser.specific_message->has_target != true)
		return (-1);
	if (parser.specific_message->target.servername != "127.0.0.1")
		return (-1);
	return (0);
}
