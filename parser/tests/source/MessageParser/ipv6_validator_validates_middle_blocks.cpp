#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_ipv6("0:0:0:0:0:0:0p:0");
	} catch (MessageParameterValidator::ErroneousIP6Exception) {
		return (0);
	}
	return (-1);
}
