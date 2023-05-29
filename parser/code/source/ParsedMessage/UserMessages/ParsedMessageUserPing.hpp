class ParsedMessageUserPing;

#ifndef PARSEDMESSAGEUSERPING_HPP
# define PARSEDMESSAGEUSERPING_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserPing : public ParsedMessage {

public:
	ParsedMessageUserPing();
	~ParsedMessageUserPing();

	target_parameter	origin_target;
	bool				has_destination_target;
	target_parameter	destination_target;
};

#endif
