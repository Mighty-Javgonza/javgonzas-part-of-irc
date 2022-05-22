#include "../tests.hpp"

int main()
{
	LexedMessage				lexedMessage;
	MessageConnectionQuitParser	parser;

	parser.parse_specific_part();
	if (parser.specific_message->has_quit_message != false)
		return (-1);
	parser.lexedMessage.parameters.push_back("Adios amigos");
	parser.parse_specific_part();
	if (parser.specific_message->has_quit_message != true || parser.specific_message->quit_message != "Adios amigos")
		return (-1);
	return (0);
}
