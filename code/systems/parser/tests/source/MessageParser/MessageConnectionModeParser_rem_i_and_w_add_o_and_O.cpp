#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionModeParser	parser;

	parser.lexedMessage.parameters.push_back("Antonio");
	parser.lexedMessage.parameters.push_back("-iw+oO");
	parser.parse_specific_part();
	int ign = ParsedMessageConnectionMode::IGNORE_MODE;
	int add = ParsedMessageConnectionMode::ADD_MODE;
	int rem = ParsedMessageConnectionMode::REMOVE_MODE;
	if (parser.specific_message->mode_i != rem)
		return (-1);
	if (parser.specific_message->mode_w != rem)
		return (-1);
	if (parser.specific_message->mode_r != ign)
		return (-1);
	if (parser.specific_message->mode_o != add)
		return (-1);
	if (parser.specific_message->mode_O != add)
		return (-1);
	return (0);
}
