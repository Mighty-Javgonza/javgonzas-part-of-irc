#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_chanstring("abc");
	try {
		MessageParameterValidator::validate_chanstring(" ,:");
	} catch (MessageParameterValidator::ErroneousChanstringException) {
		return (0);
	}
	return (-1);
}
