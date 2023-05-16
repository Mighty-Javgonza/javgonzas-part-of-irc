class MessageParser;

#ifndef MESSAGEPARSER_HPP
# define MESSAGEPARSER_HPP

# include "../ParsedMessage/ParsedMessage.hpp"
# include "../LexedMessage/LexedMessage.hpp"

class MessageParser {

public:
	MessageParser();
	~MessageParser();

	ParsedMessage	*parse(LexedMessage lexed);

protected:
	LexedMessage	lexedMessage;
	ParsedMessage	*in_progress_message;

	void	parse_common_part();
	virtual void	parse_specific_part() = 0;
	virtual	void	create_specific_message() = 0; // creates a new message of the corresponding class and stores a referennce to it in "in_progress_message"

public:
	class NeedMoreParamsException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("That command needs more params. You stupid.");
		}
	} needMoreParamsException;
};

#endif
