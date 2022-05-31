#include "../tests.hpp"

int main()
{
	msgtarget_parameter	msgtarget;

	msgtarget = MessageParameterCommonParser::parse_msgtarget("pepito,fran");
	if (msgtarget.targets.size() != 2)
		return (-1);
	if (msgtarget.targets[0].nickname != "pepito")
		return (-1);
	if (msgtarget.targets[1].nickname != "fran")
		return (-1);
	return (0);
}
