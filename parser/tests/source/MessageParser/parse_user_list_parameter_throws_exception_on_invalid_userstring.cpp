#include "../tests.hpp"

int main()
{
	user_list_parameter	user_list;

	try {
		user_list = MessageParameterCommonParser::parse_user_list("@@@");
	} catch (MessageParameterValidator::ErroneousUserStringException) {
		return (0);
	}
	return (-1);
}
