#include "Message.hpp"


Message::Message()
{
	hasPreffix = false;
}

Message::~Message()
{

}

std::string	Message::getPreffix()
{
	return (preffix);
}

std::string	Message::getCommand()
{
	return (command);
}

std::string	Message::getTrailing()
{
	return (trailing);
}

void	Message::setPreffix(std::string str)
{
	hasPreffix = true;
	preffix = str;
}

void	Message::setCommand(std::string str)
{
	hasCommand = true;
	command = str;
}

void	Message::setTrailing(std::string str)
{
	hasTrailing = true;
	trailing = str;
}

bool	Message::checkHasCommand(void)
{
	return (hasCommand);
}

bool	Message::checkHasTrailing(void)
{
	return (hasTrailing);
}

bool	Message::checkHasPreffix(void)
{
	return (hasPreffix);
}

