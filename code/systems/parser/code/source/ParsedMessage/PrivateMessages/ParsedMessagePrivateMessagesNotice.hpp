class ParsedMessagePrivateMessagesNotice;

#ifndef PARSEDMESSAGEPRIVATEMESSAGESNOTICE_HPP
# define PARSEDMESSAGEPRIVATEMESSAGESNOTICE_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessagePrivateMessagesNotice : public ParsedMessage{

public:
	ParsedMessagePrivateMessagesNotice();
	~ParsedMessagePrivateMessagesNotice();

	msgtarget_parameter	target;
	std::string			message;

private:

};

#endif
