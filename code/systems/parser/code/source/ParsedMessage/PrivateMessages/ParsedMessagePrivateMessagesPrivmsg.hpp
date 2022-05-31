class ParsedMessageConnectionPrivmsg;

#ifndef PARSEDMESSAGECONNECTIONPRIVMSG_HPP
# define PARSEDMESSAGECONNECTIONPRIVMSG_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessagePrivateMessagesPrivmsg : public ParsedMessage {

public:
	ParsedMessagePrivateMessagesPrivmsg();
	~ParsedMessagePrivateMessagesPrivmsg();

	msgtarget_parameter	target;
	std::string			message;

private:

};

#endif
