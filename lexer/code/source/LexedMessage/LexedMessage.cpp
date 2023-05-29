#include "LexedMessage.hpp"


LexedMessage::LexedMessage()
{
	hasPreffix = false;
}

LexedMessage::~LexedMessage()
{

}

std::string	LexedMessage::getPreffix()
{
	return (preffix);
}

std::string	LexedMessage::getCommand()
{
	return (command);
}

std::string	LexedMessage::getTrailing()
{
	return (trailing);
}

void	LexedMessage::setPreffix(std::string str)
{
	hasPreffix = true;
	preffix = str;
}

void	LexedMessage::setCommand(std::string str)
{
	hasCommand = true;
	command = str;
	for (size_t i = 0; i < command.length(); i++)
		command[i] = std::toupper(command[i]);
}

void	LexedMessage::setTrailing(std::string str)
{
	hasTrailing = true;
	trailing = str;
}

bool	LexedMessage::checkHasCommand(void)
{
	return (hasCommand);
}

bool	LexedMessage::checkHasTrailing(void)
{
	return (hasTrailing);
}

bool	LexedMessage::checkHasPreffix(void)
{
	return (hasPreffix);
}

void	LexedMessage::printDebug(void)
{
	if (checkHasPreffix())	
		std::cout << "Preffix: " << getPreffix() << std::endl;
	else
		std::cout << "Does not have preffix" << std::endl;
	if (checkHasCommand())	
		std::cout << "Command: " << getCommand() << std::endl;
	else
		std::cout << "Does not have command" << std::endl;
	std::cout << "Parameters: ";
	for (size_t i = 0; i < parameters.size(); i++)
		std::cout << parameters[i] << " | ";
	std::cout << std::endl;
	if (checkHasTrailing())	
		std::cout << "Trailing: " << getTrailing() << std::endl;
	else
		std::cout << "Does not have trailing" << std::endl;
}
