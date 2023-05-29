#include "../tests.hpp"

int main()
{
	channel_list_parameter	chanlist;

	chanlist = MessageParameterCommonParser::parse_channel_list("#hola");
	if (chanlist.channels[0].name != "hola")
		return (-1);
	return (0);
}
