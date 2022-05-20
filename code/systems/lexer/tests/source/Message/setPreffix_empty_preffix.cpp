#include "../tests.hpp"

int main()
{
	Message message;

	message.setPreffix("");
	if (message.checkHasPreffix() != true)
		return (-1);
	if (message.preffix != "")
		return (-1);
	return (0);
}
