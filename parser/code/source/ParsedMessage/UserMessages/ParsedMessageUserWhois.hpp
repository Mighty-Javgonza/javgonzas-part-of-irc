class ParsedMessageUserWhois;

#ifndef PARSEDMESSAGEUSERWHOIS_HPP
# define PARSEDMESSAGEUSERWHOIS_HPP

# include "../ParsedMessage.hpp"

# include "../../MessageParser/MessageParameterCommonParser.hpp"

class ParsedMessageUserWhois : public ParsedMessage {

public:
	ParsedMessageUserWhois();
	~ParsedMessageUserWhois();

	mask_list_parameter	mask_list;
	bool	has_target;
	target_parameter	target;

};

#endif
