class ParsedMessageServerTime;

#ifndef PARSEDMESSAGESERVERTIME_HPP
# define PARSEDMESSAGESERVERTIME_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageServerTime : public ParsedMessage {

public:
	ParsedMessageServerTime();
	~ParsedMessageServerTime();

	bool	has_target;
	target_parameter target;

private:

};

#endif
