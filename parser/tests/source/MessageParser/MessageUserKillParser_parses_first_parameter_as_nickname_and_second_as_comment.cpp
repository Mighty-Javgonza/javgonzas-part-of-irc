#include "../tests.hpp"

int main()
{
	MessageUserKillParser	parser;

	parser.create_specific_message();
	parser.lexedMessage.parameters.push_back("juan");
	parser.lexedMessage.parameters.push_back("Joke's on you");
	parser.parse_specific_part();
	if (parser.specific_message->nickname != "juan")
		return (-1);
	if (parser.specific_message->comment != "Joke's on you")
		return (-1);
	return (0);
}
