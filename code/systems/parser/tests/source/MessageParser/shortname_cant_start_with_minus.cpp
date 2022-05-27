#include "../tests.hpp"

int main()
{
	if (MessageParameterValidator::is_shortname("-"))
		return (-1);
	return (0);
}
