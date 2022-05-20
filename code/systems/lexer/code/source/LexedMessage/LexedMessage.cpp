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

