#include "../tests.hpp"

int main()
{
	msgto_parameter	msgto;

	msgto = MessageParameterCommonParser::parse_msgto("#yes");
	if (msgto.is_channel != true)
		return (-1);
	if (msgto.channel.name != "yes")
		return (-1);
	return (0);
}
