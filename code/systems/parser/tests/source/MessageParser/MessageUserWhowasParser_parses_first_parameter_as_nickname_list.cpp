#include "../tests.hpp"

int main()
{
	MessageUserWhowasParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("hola,adios");
	parser.parse_specific_part();
	if (parser.specific_message->nicklist.nicknames.size() != 2)
		return (-1);
	return (0);
}
