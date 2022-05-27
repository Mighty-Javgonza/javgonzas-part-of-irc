#include "../tests.hpp"

int main()
{
	channel_parameter	channel;
	channel = MessageParameterCommonParser::parse_channel("!ABCDEhola");
	if (channel.id != "ABCDE")
		return (-1);
	return (0);
}
