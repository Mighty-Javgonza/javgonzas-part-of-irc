class ParsedMessageUserKill;

#ifndef PARSEDMESSAGEUSERKILL_HPP
# define PARSEDMESSAGEUSERKILL_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserKill : public ParsedMessage {

public:
	ParsedMessageUserKill();
	~ParsedMessageUserKill();

	std::string	nickname;
	std::string	comment;

private:

};

#endif
