class CommandActionAssociator;

#ifndef COMMANDACTIONASSOCIATOR_HPP
# define COMMANDACTIONASSOCIATOR_HPP

#include "code/source/MessageParser/MessageParser.hpp"
#include "code/source/MessageParser/ConnectionMessages/MessageConnectionNickParser.hpp"
#include "../command_executor/code/source/Databasable.hpp"
#include "../command_executor/code/source/ServerInfo/ServerInfo.hpp"
#include "../input_stream_orquestator/SentMessage.hpp"
#include "../tomartin/inc/replies_generator.hpp"
#include <iostream>
#include <map>

class CommandActionAssociator {

public:
	CommandActionAssociator();
	~CommandActionAssociator();

	typedef void (*command_function)(Databasable *, SentMessage *, replies_generator *, ServerInfo *);

	MessageParser *get_parser(std::string command);
	command_function get_executor(std::string command);
	size_t get_command_id(std::string command);
	static size_t get_command_count();
	std::string	get_command_by_id(size_t cid);

	bool	is_unregistered_executable(command_function);

private:

	struct commandActuators
	{
		MessageParser 		*parser;
		command_function	executor;
		size_t				unique_id;
	};

	static size_t	command_count;
	std::map<std::string, struct commandActuators> action_map;

};

extern CommandActionAssociator	commandActionAssociator;

#endif
