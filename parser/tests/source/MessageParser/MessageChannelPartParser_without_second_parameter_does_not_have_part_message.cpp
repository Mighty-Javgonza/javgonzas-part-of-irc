#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageChannelPartParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("#hola,#adios");
	parser.parse_specific_part();
	if (parser.specific_message->has_part_message != false)
		return (-1);
	return (0);
}
