class MessageParameterCommonParser;

#ifndef MESSAGEPARAMETERCOMMONPARSER_HPP
# define MESSAGEPARAMETERCOMMONPARSER_HPP

#include <iostream>
#include <vector>

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
	bool				is_user;
	bool				is_nickname;
	bool				is_targetmask;
	bool				has_host;
	bool				has_server;
	std::string	user;
	std::string	host;
	std::string	server;
	std::string	nickname;
	channel_parameter	channel;
}				msgto_parameter;

typedef struct s_msgtarget_parameter
{
	std::vector<msgto_parameter> targets;
}				msgtarget_parameter;

typedef struct s_channel_list_parameter
{
	std::vector<channel_parameter> channels;
}				channel_list_parameter;

class MessageParameterCommonParser {

public:
	MessageParameterCommonParser();
	~MessageParameterCommonParser();

	static channel_parameter		parse_channel(std::string str);
	static channel_list_parameter	parse_channel_list(std::string str);
	static msgto_parameter			parse_msgto(std::string str);
	static msgtarget_parameter		parse_msgtarget(std::string str);
private:
	static void	parse_channel_id_part(std::string str, channel_parameter &channel);
	static void	parse_msgto_without_servername(std::string str, msgto_parameter &mgsto);
};

#endif
