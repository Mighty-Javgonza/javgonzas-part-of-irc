#include "../tests.hpp"

int main()
{
	MessageUserKillParser	parser;

	parser.create_specific_message();
	try {
		parser.parse_specific_part();
	} catch (MessageParser::NeedMoreParamsException &e) {
		parser.lexedMessage.parameters.push_back("juan");
		try {
			parser.parse_specific_part();
		} catch (MessageParser::NeedMoreParamsException &e) {
			parser.lexedMessage.parameters.push_back("Joke's on you");
			return (0);
		}
		return (-1);
	}
	return (-1);
}
