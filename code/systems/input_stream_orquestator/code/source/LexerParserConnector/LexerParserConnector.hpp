class LexerParserConnector;

#ifndef LEXERPARSERCONNECTOR_HPP
# define LEXERPARSERCONNECTOR_HPP

#include <iostream>

# include "../ParsedMessage/ParsedMessage.hpp"
# include "../LexedMessage/LexedMessage.hpp"

class LexerParserConnector {

public:
	LexerParserConnector();
	~LexerParserConnector();

	ParsedMessage *parse_string(std::string str);

private:
	template <typename MessageParserClass>
	ParsedMessage*	parse_message(LexedMessage &lexed)
	{
		MessageParserClass	parser;
		ParsedMessage	*parsed;

		parsed = parser.parse(lexed);
		return (parsed);
	}
};

#endif
