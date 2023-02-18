#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "../Databasable.hpp"
#include "../../../../input_stream_orquestator/SentMessage.hpp"
#include "../../../../input_stream_orquestator/AllParsedMessages.hpp"
#include "../../../../tomartin/inc/replies_generator.hpp"

void	command_nick(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_pass(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_user(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_privmsg(Databasable *database, SentMessage *message, replies_generator *replier);
void	command_kill(Databasable *database, SentMessage *message, replies_generator *replier);

#endif
