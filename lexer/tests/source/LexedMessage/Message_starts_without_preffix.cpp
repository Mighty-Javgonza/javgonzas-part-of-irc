#include "../tests.hpp"

int main()
{
	LexedMessage message;

	if (message.checkHasPreffix() != false)
		return (-1);
	return (0);
}
