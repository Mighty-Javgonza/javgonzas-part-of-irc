#include "../tests.hpp"

int main()
{
	msgto_parameter	msgto;

	msgto = MessageParameterCommonParser::parse_msgto("pepito@myirc.fm");
	if (msgto.is_channel != false)
		return (-1);
	if (msgto.user != "pepito")
		return (-1);
	if (msgto.has_host != false)
		return (-1);
	if (msgto.server != "myirc.fm")
		return (-1);
	return (0);
}
