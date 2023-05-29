#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_key("012345678901234567890123");
	} catch (MessageParameterValidator::ErroneousKeyException &e) {
		return (0);
	}
	return (-1);
}
