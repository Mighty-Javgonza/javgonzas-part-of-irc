#include "../tests.hpp"

int main()
{
	user_list_parameter	user_list;

	user_list = MessageParameterCommonParser::parse_user_list("juan");
	if (user_list.users[0] != "juan")
		return (-1);
	return (0);
}
