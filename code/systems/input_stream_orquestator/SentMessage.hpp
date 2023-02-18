#ifndef SENTMESSAGE_HPP
# define SENTMESSAGE_HPP

#include "code/source/ParsedMessage/ParsedMessage.hpp"
#include "../command_executor/code/source/UserID.hpp"

typedef struct s_SentMessage
{
	ParsedMessage	*message;
	UserID			*sender;
}				SentMessage;

#endif
