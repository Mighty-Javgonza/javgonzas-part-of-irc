#include "../tests.hpp"

int main()
{
	channel_parameter	channel;
	channel = MessageParameterCommonParser::parse_channel("#hola");
	if (channel.type != '#')
		return (-1);
	channel = MessageParameterCommonParser::parse_channel("+hola");
	if (channel.type != '+')
		return (-1);
	channel = MessageParameterCommonParser::parse_channel("&hola");
	if (channel.type != '&')
		return (-1);
	return (0);
}
