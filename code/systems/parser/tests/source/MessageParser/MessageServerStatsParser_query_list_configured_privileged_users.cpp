#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("o");
	parser.parse_specific_part();
	if (parser.specific_message->query.list_configured_privileged_users!= true)
		return (-1);
	if (parser.specific_message->query.id != 2)
		return (-1);
	return (0);
}
