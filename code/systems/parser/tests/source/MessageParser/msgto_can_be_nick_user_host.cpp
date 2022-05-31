#include "../tests.hpp"

int main()
{
	msgto_parameter	msgto;

	msgto = MessageParameterCommonParser::parse_msgto("nicky!francisco@myclient.dot");
	if (msgto.is_channel != false)
		return (-1);
	if (msgto.is_nickname != true)
		return (-1);
	if (msgto.nickname != "nicky")
		return (-1);
	if (msgto.has_host != true)
		return (-1);
	if (msgto.user != "francisco")
		return (-1);
	if (msgto.host != "myclient.dot")
		return (-1);
	if (msgto.has_server != false)
		return (-1);
	return (0);
}
