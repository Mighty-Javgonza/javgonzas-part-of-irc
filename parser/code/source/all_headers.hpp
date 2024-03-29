#ifndef ALL_HEADERS_PARSER_HPP
# define ALL_HEADERS_PARSER_HPP

# include "LexedMessage/LexedMessage.hpp"

# include "MessageParser/MessageParser.hpp"
# include "ParsedMessage/ParsedMessage.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionPass.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionNick.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionPassParser.hpp"
# include "MessageParser/MessageParameterValidator.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionNickParser.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionOper.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionOperParser.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionQuit.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionQuitParser.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionUser.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionUserParser.hpp"
# include "ParsedMessage/ConnectionMessages/ParsedMessageConnectionMode.hpp"
# include "MessageParser/ConnectionMessages/MessageConnectionModeParser.hpp"
# include "MessageParser/MessageParameterCommonParser.hpp"
# include "ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesPrivmsg.hpp"
# include "MessageParser/PrivateMessages/MessagePrivateMessagesPrivmsgParser.hpp"
# include "MessageParser/PrivateMessages/MessagePrivateMessagesNoticeParser.hpp"
# include "ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesNotice.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelTopic.hpp"
# include "MessageParser/ChannelMessages/MessageChannelTopicParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelNames.hpp"
# include "MessageParser/ChannelMessages/MessageChannelNamesParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelPart.hpp"
# include "MessageParser/ChannelMessages/MessageChannelPartParser.hpp"
# include "MessageParser/ChannelMessages/MessageChannelJoinParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelJoin.hpp"
# include "MessageParser/ChannelMessages/MessageChannelListParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelList.hpp"
# include "MessageParser/ChannelMessages/MessageChannelInviteParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelInvite.hpp"
# include "MessageParser/ChannelMessages/MessageChannelKickParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelKick.hpp"
# include "MessageParser/UserMessages/MessageUserWhoParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserWho.hpp"
# include "MessageParser/UserMessages/MessageUserWhoisParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserWhois.hpp"
# include "MessageParser/UserMessages/MessageUserWhowasParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserWhowas.hpp"
# include "MessageParser/UserMessages/MessageUserKillParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserKill.hpp"
# include "MessageParser/UserMessages/MessageUserPingParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserPing.hpp"
# include "MessageParser/UserMessages/MessageUserPongParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserPong.hpp"
# include "MessageParser/UserMessages/MessageUserErrorParser.hpp"
# include "ParsedMessage/UserMessages/ParsedMessageUserError.hpp"
# include "MessageParser/ServerMessages/MessageServerMotdParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerMotd.hpp"
# include "MessageParser/ServerMessages/MessageServerVersionParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerVersion.hpp"
# include "MessageParser/ServerMessages/MessageServerStatsParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerStats.hpp"
# include "MessageParser/ServerMessages/MessageServerTimeParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerTime.hpp"
# include "MessageParser/ServerMessages/MessageServerAdminParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerAdmin.hpp"
# include "MessageParser/ServerMessages/MessageServerInfoParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerInfo.hpp"
# include "MessageParser/ServerMessages/MessageServerSqueryParser.hpp"
# include "ParsedMessage/ServerMessages/ParsedMessageServerSquery.hpp"
# include "MessageParser/ChannelMessages/MessageChannelModeParser.hpp"
# include "ParsedMessage/ChannelMessages/ParsedMessageChannelMode.hpp"
# include "MessageParser/MixedParsers/ModeParser.hpp"

#endif
