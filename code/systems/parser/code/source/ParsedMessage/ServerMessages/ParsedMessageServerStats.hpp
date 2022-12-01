class ParsedMessageServerStats;

#ifndef PARSEDMESSAGESERVERSTATS_HPP
# define PARSEDMESSAGESERVERSTATS_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerStats : public ParsedMessage {

public:
	ParsedMessageServerStats();
	~ParsedMessageServerStats();

	bool	has_query;
	struct	s_query {
		int	id;
		bool	list_server_connections;
		bool	command_usage_count;
		bool	list_configured_privileged_users;
		bool	display_server_time_alive;
	};
	struct s_query query;
	bool				has_target;
	target_parameter	target;

};

#endif
