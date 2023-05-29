#include "../tests.hpp"

int main()
{
	target_parameter	target;

	try {
		target = MessageParameterCommonParser::parse_target("");
	} catch (MessageParameterValidator::ErroneousTargetException &e) {
		return (0);
	}
	return (-1);
}
