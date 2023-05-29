#include "../tests.hpp"

int main()
{
	nickname_list_parameter	nicklist;

	nicklist = MessageParameterCommonParser::parse_nickname_list("hola");
	if (nicklist.nicknames[0] != "hola")
		return (-1);
	return (0);
}
