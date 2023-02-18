#include "CommandActionAssociator.hpp"

#include "AllMessageParsers.hpp"

CommandActionAssociator::CommandActionAssociator()
{
	action_map.insert(std::make_pair("NICK", (commandActuators){.parser = new MessageConnectionNickParser}));
	action_map.insert(std::make_pair("PRIVMSG", (commandActuators){.parser = new MessagePrivateMessagesPrivmsgParser}));
	action_map.insert(std::make_pair("KILL", (commandActuators){.parser = new MessageUserKillParser}));
}

CommandActionAssociator::~CommandActionAssociator()
{

}

MessageParser	*CommandActionAssociator::get_parser(std::string command)
{
	std::map<std::string, struct commandActuators>::iterator found_element;

	found_element = action_map.find(command);
	if (found_element == action_map.end())
		return (NULL); //TODO Throw command not found
	return (found_element->second.parser);
}

CommandActionAssociator	commandActionAssociator;
