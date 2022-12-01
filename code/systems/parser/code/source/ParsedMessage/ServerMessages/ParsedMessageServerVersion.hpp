class ParsedMessageServerVersion;

#ifndef PARSEDMESSAGESERVERVERSION_HPP
# define PARSEDMESSAGESERVERVERSION_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerVersion : public ParsedMessage {

public:
	ParsedMessageServerVersion();
	~ParsedMessageServerVersion();

	bool				has_target;
	target_parameter	target;
};

#endif
