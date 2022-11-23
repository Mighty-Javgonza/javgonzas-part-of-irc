#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_key("");
	} catch (MessageParameterValidator::ErroneousKeyException) {
		return (0);
	}
	return (-1);
}
