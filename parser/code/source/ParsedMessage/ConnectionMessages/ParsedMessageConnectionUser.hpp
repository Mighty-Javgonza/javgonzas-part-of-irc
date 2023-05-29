class ParsedMessageConnectionUser;

#ifndef PARSEDMESSAGECONNECTIONUSER_HPP
# define PARSEDMESSAGECONNECTIONUSER_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionUser : public ParsedMessage{

public:
	ParsedMessageConnectionUser();
	~ParsedMessageConnectionUser();

	std::string user;
	int			mode;
	std::string	unused;
	std::string	realname;

};

#endif
