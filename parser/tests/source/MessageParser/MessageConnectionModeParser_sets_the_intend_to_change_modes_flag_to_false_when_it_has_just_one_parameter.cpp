#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionModeParser	parser;

	parser.lexedMessage.parameters.push_back("Antonio");
	parser.parse_specific_part();
	if (parser.specific_message->intends_to_change_modes != false)
		return (-1);
	return (0);
return (0);
}
