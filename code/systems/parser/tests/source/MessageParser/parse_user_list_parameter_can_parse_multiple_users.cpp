#include "../tests.hpp"

int main()
{
	user_list_parameter	user_list;

	user_list = MessageParameterCommonParser::parse_user_list("juan,pedro");
	if (user_list.users[1] != "pedro")
		return (-1);
	return (0);
}
