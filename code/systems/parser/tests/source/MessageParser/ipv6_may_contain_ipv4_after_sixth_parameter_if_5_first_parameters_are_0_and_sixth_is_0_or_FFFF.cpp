#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_ipv6("0:0:0:0:0:0:123.123.123.123");
	MessageParameterValidator::validate_ipv6("0:0:0:0:0:FFFF:123.123.123.123");
	try {
		MessageParameterValidator::validate_ipv6("0:0:0:0:6:0:123.123.123.123");
	} catch (MessageParameterValidator::ErroneousIP6Exception) {
		return (0);	
	}
	return (-1);
}
