#include "LexerParserConnector.hpp"

#include "../MessageLexer/MessageLexer.hpp"
#include "../LexedMessage/LexedMessage.hpp"
#include "../all_headers_parser.hpp"
#include "../../../CommandActionAssociator.hpp"

LexerParserConnector::LexerParserConnector()
{

}

LexerParserConnector::~LexerParserConnector()
{

}

// THINKING " 100% "
// THONKING " 4% "
ParsedMessage	*LexerParserConnector::parse_string(std::string str)
{
	ParsedMessage	*parsed;
	LexedMessage	lexed;
	MessageLexer	lexer;
	MessageParser	*parser;

	lexed = lexer.lex(str);
	std::string	command = lexed.getCommand();
	parser = commandActionAssociator.get_parser(command);
	if (parser == NULL)
		return (NULL); // TODO: BORRAR
	parsed = parser->parse(lexed);
	return (parsed);
}
