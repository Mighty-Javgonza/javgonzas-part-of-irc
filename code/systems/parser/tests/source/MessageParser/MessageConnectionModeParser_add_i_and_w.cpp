#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionModeParser	parser;

	parser.lexedMessage.parameters.push_back("Antonio");
	parser.lexedMessage.parameters.push_back("+iw");
	parser.parse_specific_part();
	int ign = ParsedMessageConnectionMode::IGNORE_MODE;
	int add = ParsedMessageConnectionMode::ADD_MODE;
	if (parser.specific_message->mode_i != add)
		return (-1);
	if (parser.specific_message->mode_w != add)
		return (-1);
	if (parser.specific_message->mode_r != ign)
		return (-1);
	if (parser.specific_message->mode_o != ign)
		return (-1);
	if (parser.specific_message->mode_O != ign)
		return (-1);
	return (0);
}
