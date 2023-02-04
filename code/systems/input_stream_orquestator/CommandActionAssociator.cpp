#include "CommandActionAssociator.hpp"


CommandActionAssociator::CommandActionAssociator()
{
	action_map.insert(std::make_pair("NICK", (commandActuators){.parser = new MessageConnectionNickParser}));
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
