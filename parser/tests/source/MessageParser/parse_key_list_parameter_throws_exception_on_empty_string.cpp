#include "../tests.hpp"

int main()
{
	key_list_parameter	key_list;

	try {
		key_list = MessageParameterCommonParser::parse_key_list("");
	} catch (MessageParameterValidator::ErroneousKeyException &e) {
		return (0);
	}
	return (-1);
}
