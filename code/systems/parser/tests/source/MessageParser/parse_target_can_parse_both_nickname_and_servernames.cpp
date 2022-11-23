#include "../tests.hpp"

int main()
{
	target_parameter	target_servername;
	target_parameter	target_nickname;

	target_servername = MessageParameterCommonParser::parse_target("127.0.0.1");
	target_nickname = MessageParameterCommonParser::parse_target("pedrito");
	if (target_servername.is_servername != true && target_servername.is_nickname != false)
		return (-1);
	if (target_servername.servername != "127.0.0.1")
		return (-1);
	if (target_nickname.is_servername != false && target_nickname.is_nickname != true)
		return (-1);
	if (target_nickname.nickname != "pedrito")
		return (-1);
	return (0);
}
