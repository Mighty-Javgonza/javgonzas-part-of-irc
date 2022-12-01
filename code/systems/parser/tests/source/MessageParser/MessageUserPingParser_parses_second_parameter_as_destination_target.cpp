#include "../tests.hpp"

int main()
{
	MessageUserPingParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("tolsun.oulu.fi");
	parser.lexedMessage.parameters.push_back("tolsun2.oulu.fi");
	parser.parse_specific_part();
	if (parser.specific_message->has_destination_target != true)
		return (-1);
	if (parser.specific_message->destination_target.servername != "tolsun2.oulu.fi")
		return (-1);
	return (0);
}
