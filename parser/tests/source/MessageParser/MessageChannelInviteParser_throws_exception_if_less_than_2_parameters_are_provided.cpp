#include "../tests.hpp"

int main()
{
	MessageChannelInviteParser	parser;

	parser.create_specific_message();
	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException &e) {
		parser.lexedMessage.parameters.push_back("nick");
		try {
			parser.parse_specific_part();
		} catch (MessageParser::NeedMoreParamsException &e) {
			parser.lexedMessage.parameters.push_back("#chan");
			parser.parse_specific_part();
			return (0);
		}
	}
	return (-1);
}
