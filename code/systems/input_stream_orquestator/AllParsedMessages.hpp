#ifndef ALLPARSEDMESSAGES_HPP
# define ALLPARSEDMESSAGES_HPP

// Todas las clases de uso público de mensajes parseados.
// El resultado de LexerParser puede ser casteado a cada una de estas clases dependiendo del comando. ("NICK" -> ParsedMessageConnectionNick)
// También se indican las rutas más abajo para poder consultar cada clase.

class ParsedMessageConnectionPass;
class ParsedMessageConnectionNick;
class ParsedMessageConnectionOper;
class ParsedMessageConnectionQuit;
class ParsedMessageConnectionUser;
class ParsedMessageConnectionMode;

class ParsedMessagePrivateMessagesPrivmsg;
class ParsedMessagePrivateMessagesNotice;

class ParsedMessageChannelTopic;
class ParsedMessageChannelNames;
class ParsedMessageChannelPart;
class ParsedMessageChannelJoin;
class ParsedMessageChannelList;
class ParsedMessageChannelInvite;
class ParsedMessageChannelKick;
class ParsedMessageChannelMode;

class ParsedMessageUserWho;
class ParsedMessageUserWhois;
class ParsedMessageUserWhowas;
class ParsedMessageUserKill;
class ParsedMessageUserPing;
class ParsedMessageUserPong;
class ParsedMessageUserError;

class ParsedMessageServerMotd;
class ParsedMessageServerVersion;
class ParsedMessageServerStats;
class ParsedMessageServerTime;
class ParsedMessageServerAdmin;
class ParsedMessageServerInfo;
class ParsedMessageServerSquery;

# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionPass.hpp"
# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionNick.hpp"
# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionOper.hpp"
# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionQuit.hpp"
# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionUser.hpp"
# include "code/source/ParsedMessage/ConnectionMessages/ParsedMessageConnectionMode.hpp"
# include "code/source/ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesPrivmsg.hpp"
# include "code/source/ParsedMessage/PrivateMessages/ParsedMessagePrivateMessagesNotice.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelTopic.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelNames.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelPart.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelJoin.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelList.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelInvite.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelKick.hpp"
# include "code/source/ParsedMessage/ChannelMessages/ParsedMessageChannelMode.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserWho.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserWhois.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserWhowas.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserKill.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserPing.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserPong.hpp"
# include "code/source/ParsedMessage/UserMessages/ParsedMessageUserError.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerMotd.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerMotd.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerVersion.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerStats.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerTime.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerAdmin.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerInfo.hpp"
# include "code/source/ParsedMessage/ServerMessages/ParsedMessageServerSquery.hpp"

#endif
