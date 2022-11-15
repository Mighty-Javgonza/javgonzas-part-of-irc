#include "MessageServerAdminParser.hpp"


MessageServerAdminParser::MessageServerAdminParser()
{

}

MessageServerAdminParser::~MessageServerAdminParser()
{

}

void	MessageServerAdminParser::parse_specific_part()
{

}

void	MessageServerAdminParser::create_specific_message()
{
	specific_message = new ParsedMessageServerAdmin();
	in_progress_message = specific_message;
}
