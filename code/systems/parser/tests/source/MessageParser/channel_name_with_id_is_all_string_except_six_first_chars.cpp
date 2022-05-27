#include "../tests.hpp"

int main()
{
	channel_parameter	channel;

	channel = MessageParameterCommonParser::parse_channel("!12345hola");
	if (channel.name != "hola")
		return (-1);
	return (0);
}
