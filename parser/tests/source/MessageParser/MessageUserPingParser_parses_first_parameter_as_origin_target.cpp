#include "../tests.hpp"

int main()
{
	MessageUserPingParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("tolsun.oulu.fi");
	parser.parse_specific_part();
	if (parser.specific_message->origin_target.servername != "tolsun.oulu.fi")
		return (-1);
	return (0);
}
