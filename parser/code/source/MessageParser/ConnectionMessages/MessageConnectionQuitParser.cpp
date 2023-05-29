#include "MessageConnectionQuitParser.hpp"


MessageConnectionQuitParser::MessageConnectionQuitParser()
{
}

MessageConnectionQuitParser::~MessageConnectionQuitParser()
{

}

void	MessageConnectionQuitParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() >= 1)
	{
		specific_message->has_quit_message = true;
		specific_message->quit_message = lexedMessage.parameters[0];
	}
	else
		specific_message->has_quit_message = false;
}

void	MessageConnectionQuitParser::create_specific_message(void)
{
	specific_message = new ParsedMessageConnectionQuit();
	in_progress_message = specific_message;
}
