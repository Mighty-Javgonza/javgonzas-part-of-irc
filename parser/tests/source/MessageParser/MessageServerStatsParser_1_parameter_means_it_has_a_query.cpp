#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("m");
	parser.parse_specific_part();
	if (parser.specific_message->has_query != true)
		return (-1);
	return (0);
}
