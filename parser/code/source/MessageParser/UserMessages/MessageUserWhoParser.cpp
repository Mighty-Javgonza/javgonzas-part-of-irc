#include "MessageUserWhoParser.hpp"


MessageUserWhoParser::MessageUserWhoParser()
{

}

MessageUserWhoParser::~MessageUserWhoParser()
{

}

void	MessageUserWhoParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() > 0)
	{
		specific_message->has_mask = true;
		specific_message->mask = lexedMessage.parameters[0];
	}
	if (lexedMessage.parameters.size() > 1)
		if (lexedMessage.parameters[1] == "o")
			specific_message->just_operators= true;
}

void	MessageUserWhoParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWho();
	in_progress_message = specific_message;
}
