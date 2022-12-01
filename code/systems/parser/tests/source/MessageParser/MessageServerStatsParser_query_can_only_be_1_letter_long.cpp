#include "../tests.hpp"

int main()
{
	MessageServerStatsParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("ma");
	try {
		parser.parse_specific_part();
	} catch (MessageParameterValidator::ErroneousQueryException &e) {
		return (0);
	}
	return (-1);
}
