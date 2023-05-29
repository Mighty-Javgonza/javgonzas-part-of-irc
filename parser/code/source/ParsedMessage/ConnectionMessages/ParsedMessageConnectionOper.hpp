class ParsedMessageConnectionOper;

#ifndef PARSEDMESSAGECONNECTIONOPER_HPP
# define PARSEDMESSAGECONNECTIONOPER_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionOper : public ParsedMessage{

public:
	ParsedMessageConnectionOper();
	~ParsedMessageConnectionOper();

	std::string	name;
	std::string	password;

};

#endif
