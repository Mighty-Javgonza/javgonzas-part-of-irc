#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_user("asd@");
	} catch (MessageParameterValidator::ErroneousUserStringException) {
		return (0);
	}
	return (-1);
}
