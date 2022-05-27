class MessageParameterCommonParser;

#ifndef MESSAGEPARAMETERCOMMONPARSER_HPP
# define MESSAGEPARAMETERCOMMONPARSER_HPP

#include <iostream>

#include "MessageParameterValidator.hpp"

typedef struct s_channel_parameter
{
	char		type;
	std::string	id;
	std::string	name;
	std::string	mask;
}				channel_parameter;

typedef struct s_msgto_parameter
{
	bool				is_channel; //If not channel then it is a user
	channel_parameter	channel;
	bool				has_host;
	std::string	user;
	std::string	host;
	std::string	server;
}				msgto_parameter;

class MessageParameterCommonParser {

public:
	MessageParameterCommonParser();
	~MessageParameterCommonParser();

	static channel_parameter	parse_channel(std::string str);
	static msgto_parameter		parse_msgto(std::string str);
private:
	static void	parse_channel_id_part(std::string str, channel_parameter &channel);
};

#endif
