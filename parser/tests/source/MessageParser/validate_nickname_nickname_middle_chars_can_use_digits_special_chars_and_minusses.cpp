#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_nickname("a-b-3-[");
	} catch (MessageParameterValidator::ErroneousNicknameException) {
		return (-1);
	}
	return (0);
}
