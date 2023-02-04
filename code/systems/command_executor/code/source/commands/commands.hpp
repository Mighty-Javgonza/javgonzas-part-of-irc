#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "../Databasable.hpp"
#include "../Replierable.hpp"
#include "../../../../input_stream_orquestator/SentMessage.hpp"
#include "../../../../input_stream_orquestator/AllParsedMessages.hpp"

void	command_nick(Databasable *database, SentMessage *message, Replierable *replier);

#endif
