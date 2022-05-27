#include "../tests.hpp"

int main()
{
	if (!MessageParameterValidator::is_shortname("a-b"))
		return (-1);
	return (0);
}
