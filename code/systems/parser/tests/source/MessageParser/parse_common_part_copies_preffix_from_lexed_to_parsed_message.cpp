#include "../tests.hpp"

class MessageParserTestWrapper : public MessageParser{
	void	parse_specific_part(){
	};
	void	create_specific_message() {};
};

int main()
{
	LexedMessage				lexedMessage;
	MessageParserTestWrapper	parser;
	ParsedMessage				*result;

	lexedMessage.preffix = "user@host";
	parser.lexedMessage = lexedMessage;
	parser.parse_common_part();
	result = parser.in_progress_message;
	if (result->preffix != "user@host")
		return (-1);
	return (0);
}
