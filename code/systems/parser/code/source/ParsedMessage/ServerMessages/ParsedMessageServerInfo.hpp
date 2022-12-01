class ParsedMessageServerInfo;

#ifndef PARSEDMESSAGESERVERINFO_HPP
# define PARSEDMESSAGESERVERINFO_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerInfo : public ParsedMessage {

public:
	ParsedMessageServerInfo();
	~ParsedMessageServerInfo();

	bool 				has_target;
	target_parameter	target;

};

#endif
