#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_ipv6("000+0+0+0+0+0+0+0");
	} catch (MessageParameterValidator::ErroneousIP6Exception) {
		return (0);
	}
	return (-1);
}
