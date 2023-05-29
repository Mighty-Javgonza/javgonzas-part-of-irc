#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_ipv4("123.123.123.123");
	MessageParameterValidator::validate_ipv4("12.03.0.123");
	MessageParameterValidator::validate_ipv4("1.2.3.4");
	return (0);
}
