#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_nickname("9jacinto");
	} catch (MessageParameterValidator::ErroneousNicknameException) {
		return (0);
	}
	return (-1);
}
