#ifndef SENTMESSAGE_HPP
# define SENTMESSAGE_HPP

#include "code/source/ParsedMessage/ParsedMessage.hpp"
#include "../tomartin/inc/user.hpp" //TODO Provisional user. Use the one form the DB when created

typedef struct s_SentMessage
{
	ParsedMessage	*message;
	user			*sender;
}				SentMessage;

#endif
