#include "../tests.hpp"

int main()
{
	key_list_parameter	key_list;

	key_list = MessageParameterCommonParser::parse_key_list("abc,def");
	if (key_list.keys[1] != "def")
		return (-1);
	return (0);
}
