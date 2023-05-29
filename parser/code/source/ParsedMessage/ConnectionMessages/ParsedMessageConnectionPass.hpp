class ParsedMessageConnectionPass;

#ifndef PARSEDMESSAGECONNECTIONPASS_HPP
# define PARSEDMESSAGECONNECTIONPASS_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionPass : public ParsedMessage {

public:
	ParsedMessageConnectionPass();
	~ParsedMessageConnectionPass();

	std::string	password;

private:

};

#endif
