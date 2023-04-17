#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "../Databasable.hpp"
#include "../ServerInfo/ServerInfo.hpp"
#include "../../../../input_stream_orquestator/SentMessage.hpp"
#include "../../../../input_stream_orquestator/AllParsedMessages.hpp"
#include "../../../../tomartin/inc/replies_generator.hpp"
#include "../../../../vicmarti/src/db/chan.hpp"

void	command_nick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_user(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_mode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_oper(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_part(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	part_user_from_chan(Client *client, Chan *chan, bool has_comment, std::string comment, Databasable *database);
void	command_topic(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_invite(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_kick(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_names(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_list(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_chanmode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_notice(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);

void	send_text_message_to_target(Client *sender, std::string message_str, msgto_parameter *t, Databasable *database, std::string level, replies_generator *replier);
void	send_message_to_users_in_chan(std::string message, Chan *channel, Databasable *database);

#endif
