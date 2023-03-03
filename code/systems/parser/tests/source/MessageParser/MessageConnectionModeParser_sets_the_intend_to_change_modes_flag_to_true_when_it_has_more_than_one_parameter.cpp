#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionModeParser	parser;

	parser.lexedMessage.parameters.push_back("Antonio");
	parser.lexedMessage.parameters.push_back("+i");
	parser.parse_specific_part();
	if (parser.specific_message->intends_to_change_modes != true)
		return (-1);
	return (0);
}
