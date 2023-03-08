#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "../Databasable.hpp"
#include "../ServerInfo/ServerInfo.hpp"
#include "../../../../input_stream_orquestator/SentMessage.hpp"
#include "../../../../input_stream_orquestator/AllParsedMessages.hpp"
#include "../../../../tomartin/inc/replies_generator.hpp"

void	command_nick(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_user(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_mode(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_oper(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_part(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);
void	command_topic(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info);

void	send_message_to_user_vector(std::vector<User> users, std::string message);

#endif
