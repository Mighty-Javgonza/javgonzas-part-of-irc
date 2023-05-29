#include "../tests.hpp"

int main()
{

	try {
		MessageParameterValidator::validate_ipv4("000+000+000+000");
	} catch (MessageParameterValidator::ErroneousIP4Exception) {
		return (0);
	}
	return (-1);
}
