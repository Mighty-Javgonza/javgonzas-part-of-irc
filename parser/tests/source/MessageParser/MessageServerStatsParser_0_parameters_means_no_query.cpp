#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.parse_specific_part();
	if (parser.specific_message->has_query != false)
		return (-1);
	return (0);
}
