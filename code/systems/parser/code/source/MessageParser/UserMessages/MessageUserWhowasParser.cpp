#include "MessageUserWhowasParser.hpp"


MessageUserWhowasParser::MessageUserWhowasParser()
{

}

MessageUserWhowasParser::~MessageUserWhowasParser()
{

}

void	MessageUserWhowasParser::parse_specific_part()
{
	if (lexedMessage.parameters.size() == 0)
		throw (needMoreParamsException);
	specific_message->nicklist = MessageParameterCommonParser::parse_nickname_list(lexedMessage.parameters[0]);
	if (lexedMessage.parameters.size() > 1)
	{
		std::string	count_string = lexedMessage.parameters[1];
		bool	valid_count = true;

		for (size_t i = 0; i < count_string.length(); i++)
			if (!std::isdigit(count_string[i]))
				valid_count = false;
		if (valid_count)
		{
			specific_message->count = std::stoi(count_string);
			specific_message->has_count = true;
			if (lexedMessage.parameters.size() > 2)
			{
				specific_message->has_target = true;
				specific_message->target = MessageParameterCommonParser::parse_target(lexedMessage.parameters[2]);
			}
		}
	}
}

void	MessageUserWhowasParser::create_specific_message()
{
	specific_message = new ParsedMessageUserWhowas();
	in_progress_message = specific_message;
}
