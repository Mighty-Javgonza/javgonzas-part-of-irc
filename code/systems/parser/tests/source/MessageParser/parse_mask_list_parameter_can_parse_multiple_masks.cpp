#include "../tests.hpp"

int main()
{
	mask_list_parameter	mask_list;

	mask_list = MessageParameterCommonParser::parse_mask_list("abc,def");
	if (mask_list.masks[1] != "def")
		return (-1);
	return (0);
}
