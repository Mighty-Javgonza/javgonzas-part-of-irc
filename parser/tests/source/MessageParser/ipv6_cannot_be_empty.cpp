#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_ipv6("");
	} catch (MessageParameterValidator::ErroneousIP6Exception) {
	}
	return (0);
}
