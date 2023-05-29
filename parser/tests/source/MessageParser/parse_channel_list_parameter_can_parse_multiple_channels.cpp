#include "../tests.hpp"

int main()
{
	channel_list_parameter	chanlist;

	chanlist = MessageParameterCommonParser::parse_channel_list("#hola,#adios");
	if (chanlist.channels[1].name != "adios")
		return (-1);
	return (0);
}
