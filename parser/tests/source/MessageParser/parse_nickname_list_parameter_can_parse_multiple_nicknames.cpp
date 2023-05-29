#include "../tests.hpp"

int main()
{
	nickname_list_parameter	nicklist;

	nicklist = MessageParameterCommonParser::parse_nickname_list("hola,adios");
	if (nicklist.nicknames[1] != "adios")
		return (-1);
	return (0);
}
