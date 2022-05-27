#include "../tests.hpp"

int main()
{

	try {
		MessageParameterValidator::validate_ipv4("000.1234.00.000");
	} catch (MessageParameterValidator::ErroneousIP4Exception) {
		return (0);
	}
	return (-1);
}
