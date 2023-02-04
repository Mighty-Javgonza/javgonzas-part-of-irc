class CommandActionAssociator;

#ifndef COMMANDACTIONASSOCIATOR_HPP
# define COMMANDACTIONASSOCIATOR_HPP

#include "code/source/MessageParser/MessageParser.hpp"
#include "code/source/MessageParser/ConnectionMessages/MessageConnectionNickParser.hpp"
#include <iostream>
#include <map>

class CommandActionAssociator {

public:
	CommandActionAssociator();
	~CommandActionAssociator();

	MessageParser *get_parser(std::string command);

private:

	struct commandActuators
	{
		MessageParser *parser;
//		CommandExecutor *executor; //Add when commands get created
	};

	std::map<std::string, struct commandActuators> action_map;

};

extern CommandActionAssociator	commandActionAssociator;

#endif
