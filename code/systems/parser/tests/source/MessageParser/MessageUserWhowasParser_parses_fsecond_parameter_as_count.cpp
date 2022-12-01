#include "../tests.hpp"

int main()
{
	MessageUserWhowasParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("hola,adios");
	parser.lexedMessage.parameters.push_back("17");
	parser.parse_specific_part();
	if (parser.specific_message->has_count != true)
		return (-1);
	if (parser.specific_message->count != 17)
		return (-1);
	return (0);
}
