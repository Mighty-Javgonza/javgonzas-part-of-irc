class ParsedMessageConnectionMode;

#ifndef PARSEDMESSAGECONNECTIONMODE_HPP
# define PARSEDMESSAGECONNECTIONMODE_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionMode : public ParsedMessage{

public:
	ParsedMessageConnectionMode();
	~ParsedMessageConnectionMode();

	static const int	IGNORE_MODE;
	static const int	ADD_MODE;
	static const int	REMOVE_MODE;

	std::string	nickname;
	int	mode_i;
	int	mode_w;
	int	mode_r;
	int	mode_o;
	int	mode_O;

};

#endif
