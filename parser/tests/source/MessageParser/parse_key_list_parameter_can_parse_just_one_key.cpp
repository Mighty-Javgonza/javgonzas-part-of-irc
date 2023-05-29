#include "../tests.hpp"

int main()
{
	key_list_parameter	key_list;

	key_list = MessageParameterCommonParser::parse_key_list("abc");
	if (key_list.keys[0] != "abc")
		return (-1);
	return (0);
}
