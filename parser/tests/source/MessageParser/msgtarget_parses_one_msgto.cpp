#include "../tests.hpp"

int main()
{
	msgtarget_parameter	msgtarget;

	msgtarget = MessageParameterCommonParser::parse_msgtarget("pepito");
	if (msgtarget.targets.size() != 1)
		return (-1);
	if (msgtarget.targets[0].nickname != "pepito")
		return (-1);
	return (0);
}
