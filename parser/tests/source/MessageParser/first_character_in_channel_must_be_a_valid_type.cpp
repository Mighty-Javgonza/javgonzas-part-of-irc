#include "../tests.hpp"

int main()
{
	channel_parameter	channel;
	try {
		channel = MessageParameterCommonParser::parse_channel("hola");
	} catch (MessageParameterValidator::ErroneousChannelException) {
		return (0);
	}
	return (-1);
}
