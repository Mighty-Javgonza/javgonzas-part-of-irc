#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("m");
	parser.parse_specific_part();
	if (parser.specific_message->query.list_server_connections != false)
		return (-1);
	if (parser.specific_message->query.command_usage_count != true)
		return (-1);
	if (parser.specific_message->query.id != 1)
		return (-1);
	return (0);
}
