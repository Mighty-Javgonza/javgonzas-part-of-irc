class ParsedMessageConnectionQuit;

#ifndef PARSEDMESSAGECONNECTIONQUIT_HPP
# define PARSEDMESSAGECONNECTIONQUIT_HPP

# include "../ParsedMessage.hpp"

class ParsedMessageConnectionQuit : public ParsedMessage {

public:
	ParsedMessageConnectionQuit();
	~ParsedMessageConnectionQuit();

	std::string	quit_message;
	bool	has_quit_message;

private:

};

#endif
