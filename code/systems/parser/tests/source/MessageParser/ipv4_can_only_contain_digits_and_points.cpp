#include "../tests.hpp"

int main()
{

	try {
		MessageParameterValidator::validate_ipv4("a.0.0.0");
	} catch (MessageParameterValidator::ErroneousIP4Exception) {
		return (0);
	}
	return (-1);
}
