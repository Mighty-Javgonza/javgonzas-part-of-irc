#include "../tests.hpp"

int main()
{
	channel_parameter	channel;
	try {
		channel = MessageParameterCommonParser::parse_channel("!ABCD");
	} catch (MessageParameterValidator::ErroneousChannelidException) {
		try {
			channel = MessageParameterCommonParser::parse_channel("!*BCDE");
		} catch (MessageParameterValidator::ErroneousChannelidException) {
			return (0);
		}
	}
	return (-1);
}
