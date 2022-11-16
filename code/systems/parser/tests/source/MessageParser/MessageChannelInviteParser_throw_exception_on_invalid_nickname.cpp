#include "../tests.hpp"

int main()
{
	MessageChannelInviteParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("9814");
	parser.lexedMessage.parameters.push_back("#chan");
	try {
		parser.parse_specific_part();
	} catch (MessageParameterValidator::ErroneousNicknameException &e) {
		return (0);
	}
	return (-1);
}
