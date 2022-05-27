#include "../tests.hpp"

int main()
{
	if (MessageParameterValidator::is_shortname("a-"))
		return (-1);
	return (0);
}
