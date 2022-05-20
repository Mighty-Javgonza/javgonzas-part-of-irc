#include "../tests.hpp"

int main()
{
	Message message;

	if (message.checkHasCommand() != false)
		return (-1);
	message.setCommand("tututu");
	if (message.checkHasCommand() != true)
		return (-1);
	if (message.hasCommand != true)
		return (-1);
	if (message.command != "tututu")
		return (-1);
	if (message.getCommand() != "tututu")
		return (-1);
	return (0);
}
