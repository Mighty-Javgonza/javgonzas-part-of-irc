class ParsedMessageUserPong;

#ifndef PARSEDMESSAGEUSERPONG_HPP
# define PARSEDMESSAGEUSERPONG_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserPong : public ParsedMessage {

public:
	ParsedMessageUserPong();
	~ParsedMessageUserPong();

	target_parameter	origin_target;
	bool				has_destination_target;
	target_parameter	destination_target;

};

#endif
