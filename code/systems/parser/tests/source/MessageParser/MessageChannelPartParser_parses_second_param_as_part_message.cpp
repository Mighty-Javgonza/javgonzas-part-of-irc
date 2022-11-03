#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageChannelPartParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.lexedMessage.parameters.push_back("ME VOY");
	parser.parse_specific_part();
	if (parser.specific_message->has_part_message != true)
		return (-1);
	if (parser.specific_message->part_message != "ME VOY")
		return (-1);
	return (0);
}
