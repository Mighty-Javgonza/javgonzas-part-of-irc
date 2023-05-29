class ParsedMessageUserWho;

#ifndef PARSEDMESSAGEUSERWHO_HPP
# define PARSEDMESSAGEUSERWHO_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserWho : public ParsedMessage {

public:
	ParsedMessageUserWho();
	~ParsedMessageUserWho();

	bool		has_mask;
	std::string	mask;
	bool		just_operators;
};

#endif
