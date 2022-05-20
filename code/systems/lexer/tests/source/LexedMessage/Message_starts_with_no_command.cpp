#include "../tests.hpp"

int main()
{
	LexedMessage message;

	if (message.checkHasCommand() != false)
		return (-1);
	if (message.command != "")
		return (-1);
	return (0);
}
