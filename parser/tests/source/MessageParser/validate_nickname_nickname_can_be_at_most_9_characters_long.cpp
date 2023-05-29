#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_nickname("a234567890");
	} catch (MessageParameterValidator::ErroneousNicknameException) {
		try {
			MessageParameterValidator::validate_nickname("a23456789");
		} catch (MessageParameterValidator::ErroneousNicknameException) {
			return (-1);
		}
		return (0);
	}
	return (-1);
}
