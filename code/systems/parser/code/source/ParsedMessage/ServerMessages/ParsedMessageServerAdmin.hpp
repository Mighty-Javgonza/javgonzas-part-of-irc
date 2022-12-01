class ParsedMessageServerAdmin;

#ifndef PARSEDMESSAGESERVERADMIN_HPP
# define PARSEDMESSAGESERVERADMIN_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerAdmin : public ParsedMessage {

public:
	ParsedMessageServerAdmin();
	~ParsedMessageServerAdmin();

	bool 				has_target;
	target_parameter	target;
};

#endif
