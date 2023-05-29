#include "../tests.hpp"

int main()
{
	msgto_parameter	msgto;

	msgto = MessageParameterCommonParser::parse_msgto("pepito%hola.adios");
	if (msgto.is_channel != false)
		return (-1);
	if (msgto.user != "pepito")
		return (-1);
	if (msgto.has_host != true)
		return (-1);
	if (msgto.host != "hola.adios")
		return (-1);
	if (msgto.has_server != false)
		return (-1);
	return (0);
}
