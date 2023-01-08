#include "LexerParserConnector.hpp"

#include "../MessageLexer/MessageLexer.hpp"
#include "../LexedMessage/LexedMessage.hpp"
#include "../all_headers_parser.hpp"

LexerParserConnector::LexerParserConnector()
{

}

LexerParserConnector::~LexerParserConnector()
{

}

//TODO: This function wants a rethinking
//TODO: Preinstantiate parser classes.
// THINKING " 37% "
ParsedMessage	*LexerParserConnector::parse_string(std::string str)
{
	ParsedMessage	*parsed;
	LexedMessage	lexed;
	MessageLexer	lexer;

	lexed = lexer.lex(str);
	std::string	c = lexed.getCommand();
	if (c == "NICK")
		parsed = parse_message<MessageConnectionNickParser>(lexed);
	else if (c == "PASS")
		parsed = parse_message<MessageConnectionPassParser>(lexed);
	else if (c == "USER")
		parsed = parse_message<MessageConnectionUserParser>(lexed);
	else if (c == "OPER")
		parsed = parse_message<MessageConnectionOperParser>(lexed);
	else if (c == "MODE")
		parsed = parse_message<MessageConnectionModeParser>(lexed);
	else if (c == "QUIT")
		parsed = parse_message<MessageConnectionQuitParser>(lexed);
	else if (c == "JOIN")
		parsed = parse_message<MessageChannelJoinParser>(lexed);
	else if (c == "PART")
		parsed = parse_message<MessageChannelPartParser>(lexed);
	else if (c == "MODE")
		parsed = parse_message<MessageChannelModeParser>(lexed);
	else if (c == "TOPIC")
		parsed = parse_message<MessageChannelTopicParser>(lexed);
	else if (c == "NAMES")
		parsed = parse_message<MessageChannelNamesParser>(lexed);
	else if (c == "LIST")
		parsed = parse_message<MessageChannelListParser>(lexed);
	else if (c == "INVITE")
		parsed = parse_message<MessageChannelInviteParser>(lexed);
	else if (c == "KICK")
		parsed = parse_message<MessageChannelKickParser>(lexed);
	else if (c == "PRIVMSG")
		parsed = parse_message<MessagePrivateMessagesPrivmsgParser>(lexed);
	else if (c == "NOTICE")
		parsed = parse_message<MessagePrivateMessagesNoticeParser>(lexed);
	else if (c == "MOTD")
		parsed = parse_message<MessageServerMotdParser>(lexed);
	else if (c == "VERSION")
		parsed = parse_message<MessageServerVersionParser>(lexed);
	else if (c == "STATS")
		parsed = parse_message<MessageServerStatsParser>(lexed);
	else if (c == "TIME")
		parsed = parse_message<MessageServerTimeParser>(lexed);
	else if (c == "ADMIN")
		parsed = parse_message<MessageServerAdminParser>(lexed);
	else if (c == "INFO")
		parsed = parse_message<MessageServerInfoParser>(lexed);
	else if (c == "WHO")
		parsed = parse_message<MessageUserWhoParser>(lexed);
	else if (c == "WHOIS")
		parsed = parse_message<MessageUserWhoisParser>(lexed);
	else if (c == "WHOWAS")
		parsed = parse_message<MessageUserWhowasParser>(lexed);
	else if (c == "KILL")
		parsed = parse_message<MessageUserKillParser>(lexed);
	else if (c == "PING")
		parsed = parse_message<MessageUserPingParser>(lexed);
	else if (c == "PONG")
		parsed = parse_message<MessageUserPongParser>(lexed);
	else if (c == "ERROR")
		parsed = parse_message<MessageUserErrorParser>(lexed);
	else
		parsed = NULL;
	return (parsed);
}
