#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_host("abc.123.com");
	MessageParameterValidator::validate_host("145.68.25.14");
	return (0);
}
