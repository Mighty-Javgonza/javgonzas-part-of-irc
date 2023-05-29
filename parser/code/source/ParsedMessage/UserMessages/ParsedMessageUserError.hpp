class ParsedMessageUserError;

#ifndef PARSEDMESSAGEUSERERROR_HPP
# define PARSEDMESSAGEUSERERROR_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserError : public ParsedMessage {

public:
	ParsedMessageUserError();
	~ParsedMessageUserError();

	std::string	error_message;

};

#endif
