#include "../tests.hpp"

int main()
{
	channel_list_parameter	chanlist;

	try {
		chanlist = MessageParameterCommonParser::parse_channel_list("");
	} catch (MessageParameterValidator::ErroneousChannelException) {
		return (0);
	}
	return (-1);
}
