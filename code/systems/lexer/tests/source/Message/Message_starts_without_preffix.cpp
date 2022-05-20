#include "../tests.hpp"

int main()
{
	Message message;

	if (message.checkHasPreffix() != false)
		return (-1);
	return (0);
}
