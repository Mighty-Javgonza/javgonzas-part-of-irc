#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("l");
	parser.parse_specific_part();
	if (parser.specific_message->query.list_server_connections != true)
		return (-1);
	if (parser.specific_message->query.id != 0)
		return (-1);
	return (0);
}
