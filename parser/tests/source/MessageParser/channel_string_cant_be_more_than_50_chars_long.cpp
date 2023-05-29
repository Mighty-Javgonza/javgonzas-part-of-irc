#include "../tests.hpp"

int main()
{
	channel_parameter	channel;
	std::string			chan_str;

	chan_str = "#";
	for (int i = 0; i < 50; i++)
		chan_str += "a";
	try {
		channel = MessageParameterCommonParser::parse_channel(chan_str);
	} catch (MessageParameterValidator::ErroneousChannelException){
		return (0);
	}
	return (-1);
}
