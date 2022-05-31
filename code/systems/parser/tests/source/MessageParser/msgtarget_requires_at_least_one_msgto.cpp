#include "../tests.hpp"

int main()
{
	msgtarget_parameter	msgtarget;

	std::vector<std::string> parameters;
	try {
		msgtarget = MessageParameterCommonParser::parse_msgtarget("");
	} catch (MessageParameterValidator::ErroneousMsgtargetException) {
		return (0);
	}
	return (-1);
}
