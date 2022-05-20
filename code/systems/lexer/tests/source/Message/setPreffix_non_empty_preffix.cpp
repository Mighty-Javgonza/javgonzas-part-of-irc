#include "../tests.hpp"

int main()
{
	Message message;

	message.setPreffix("aaa");
	if (message.checkHasPreffix() != true)
		return (-1);
	if (message.preffix != "aaa")
		return (-1);
	return (0);
}
