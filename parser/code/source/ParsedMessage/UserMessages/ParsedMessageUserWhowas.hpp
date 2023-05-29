class ParsedMessageUserWhowas;

#ifndef PARSEDMESSAGEUSERWHOWAS_HPP
# define PARSEDMESSAGEUSERWHOWAS_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserWhowas : public ParsedMessage {

public:
	ParsedMessageUserWhowas();
	~ParsedMessageUserWhowas();

	nickname_list_parameter	nicklist;
	bool	has_count;
	size_t	count;
	bool	has_target;
	target_parameter	target;

};

#endif
