#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("u");
	parser.parse_specific_part();
	if (parser.specific_message->query.display_server_time_alive != true)
		return (-1);
	if (parser.specific_message->query.id != 3)
		return (-1);
	return (0);
}
