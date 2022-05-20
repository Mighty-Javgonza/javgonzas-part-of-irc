#include "../tests.hpp"

int main()
{
	Message message;

	if (message.checkHasTrailing() != false)
		return (false);
	message.setTrailing("aaa");
	if (message.checkHasTrailing() != true)
		return (-1);
	if (message.getTrailing() != "aaa")
		return (-1);
	return (0);
}
