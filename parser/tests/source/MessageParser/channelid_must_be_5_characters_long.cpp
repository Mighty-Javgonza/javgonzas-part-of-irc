#include "../tests.hpp"

int main()
{
	MessageParameterValidator::validate_channelid("abcde");
	try {
		MessageParameterValidator::validate_channelid("123456");
	} catch (MessageParameterValidator::ErroneousChannelidException) {
		try {
			MessageParameterValidator::validate_channelid("1234");
		} catch (MessageParameterValidator::ErroneousChannelidException) {
			return (0);
		}
		return (-1);
	}
	return (-1);
}
