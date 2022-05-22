#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionModeParser	parser;

	parser.lexedMessage.parameters.push_back("3tonio");
	try {
		parser.parse_specific_part();
	} catch (MessageParameterValidator::ErroneousNicknameException) {
		return (0);
	}
	return (-1);
}
