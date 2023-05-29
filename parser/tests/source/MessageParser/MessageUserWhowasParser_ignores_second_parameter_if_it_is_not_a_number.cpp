#include "../tests.hpp"

int main()
{
	MessageUserWhowasParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("hola,adios");
	parser.lexedMessage.parameters.push_back("1g7");
	parser.parse_specific_part();
	if (parser.specific_message->has_count != false)
		return (-1);
	if (parser.specific_message->has_target != false)
		return (-1);
	return (0);
}
