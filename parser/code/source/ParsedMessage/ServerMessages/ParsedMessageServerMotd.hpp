class ParsedMessageServerMotd;

#ifndef PARSEDMESSAGESERVERMOTD_HPP
# define PARSEDMESSAGESERVERMOTD_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerMotd : public ParsedMessage {

public:
	ParsedMessageServerMotd();
	~ParsedMessageServerMotd();

	bool				has_target;
	target_parameter	target;
};

#endif
