class ParsedMessageConnectionNick;

#ifndef PARSEDMESSAGECONNECTIONNICK_HPP
# define PARSEDMESSAGECONNECTIONNICK_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionNick : public ParsedMessage {

public:
	ParsedMessageConnectionNick();
	~ParsedMessageConnectionNick();

	std::string	nickname;

private:

};

#endif
