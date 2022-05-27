#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_hostaddr("0:0:0:0:0:0:123.123.123.123");
	MessageParameterValidator::validate_hostaddr("123.123.123.123");
	return (0);
}
