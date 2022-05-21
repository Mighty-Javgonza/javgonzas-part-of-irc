#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_nickname("a$$");
	} catch (MessageParameterValidator::ErroneousNicknameException) {
		return (0);
	}
	return (-1);
}
