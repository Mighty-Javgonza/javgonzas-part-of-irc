#include "MessageServerStatsParser.hpp"


MessageServerStatsParser::MessageServerStatsParser()
{

}

MessageServerStatsParser::~MessageServerStatsParser()
{

}

void	MessageServerStatsParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)	
	{
		std::string	query_str = lexedMessage.parameters[0];
		specific_message->has_query = true;
		if (query_str.length() > 1 || query_str.length() == 0)
			throw (MessageParameterValidator::erroneousQueryException);
		switch (query_str[0]) {
			case 'l':
				specific_message->query.id = 0;
				specific_message->query.list_server_connections = true;
				break;
			case 'm':
				specific_message->query.id = 1;
				specific_message->query.command_usage_count = true;
				break;
			case 'o':
				specific_message->query.id = 2;
				specific_message->query.list_configured_privileged_users = true;
				break;
			case 'u':
				specific_message->query.id = 3;
				specific_message->query.display_server_time_alive = true;
				break;
			case 'd':
				specific_message->query.id = 4;
				specific_message->query.number_of_database_get_from_fd = true;
				break;
			default :
				throw (MessageParameterValidator::erroneousQueryException);
		}
	}
	if (lexedMessage.parameters.size() > 1)
	{
		specific_message->has_target = true;
		specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[1]);
	}
}

void	MessageServerStatsParser::create_specific_message()
{
	specific_message = new ParsedMessageServerStats();
	in_progress_message = specific_message;
}
