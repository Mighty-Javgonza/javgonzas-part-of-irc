#include "MessageLexer.hpp"

MessageLexer::MessageLexer()
{

}

MessageLexer::~MessageLexer()
{

}

LexedMessage	MessageLexer::lex(std::string str)
{
	setAnalysisString(str);
	setMessagePreffixIfItExists();
	if (analyzed_chars >= analysis_string.length())
		throw (missingCommandException);
	in_progress_message.setCommand(getNextWord());
	validateCommandString(in_progress_message.getCommand());
	storeParameters();
	return (in_progress_message);
}

void	MessageLexer::setMessagePreffixIfItExists()
{
	if (analysis_string[0] == ':')
	{
		if (analysis_string[1] == ' ')
			throw (preffixStartsWithSpaceException);
		analyzed_chars++;
		in_progress_message.setPreffix(getNextWord());
	}
}

std::string	MessageLexer::getNextWord()
{
	std::string word;
	size_t	next_space;
	size_t	word_end;

	next_space = analysis_string.find_first_of(' ', analyzed_chars);
	if (next_space == std::string::npos)
		word_end = analysis_string.length(); 
	else
		word_end = next_space;
	word = analysis_string.substr(analyzed_chars, word_end - analyzed_chars);
	analyzed_chars = word_end + 1;
	return (word);
}

void	MessageLexer::setAnalysisString(std::string str)
{
	LexedMessage	blank_message;

	analysis_string = str;
	analyzed_chars = 0;
	in_progress_message = blank_message;
}

void	MessageLexer::storeParameters(void)
{
	while (analyzed_chars < analysis_string.length())
	{
		if (analysis_string[analyzed_chars] == ':')
		{
			analyzed_chars++;
			putRestOfAnalysisStringInTrailing();
			break;
		} else if (in_progress_message.parameters.size() == 14) {
			putRestOfAnalysisStringInTrailing();
			break;
		} else
		{
			std::string	new_parameter;

			new_parameter = getNextWord();
			validateParameterString(new_parameter);
			in_progress_message.parameters.push_back(new_parameter);
		}
	}
}

void	MessageLexer::putRestOfAnalysisStringInTrailing()
{
	std::string trailing_chars;

	trailing_chars = analysis_string.substr(analyzed_chars, analysis_string.size() - analyzed_chars);
	validateTrailingString(trailing_chars);
	in_progress_message.setTrailing(trailing_chars);
}

void	MessageLexer::validateCommandString(std::string str)
{
	if (str.length() == 0)
		throw (emptyCommandException);
	if (std::isalpha(str[0]))
	{
		for (size_t i = 1; i < str.length(); i++)
			if (!std::isalpha(str[i]))
				throw (letterCommandContainsNonLetterException);
	} else if (std::isdigit(str[0])){
		if (str.length() != 3)
			throw (numericCommandIsNotThreeDigitsLongException);
		else
			for (size_t i = 1; i < str.length(); i++)
				if (!std::isdigit(str[i]))
					throw (numericCommandContainNonDigitsException);
	}
}

void	MessageLexer::validateParameterString(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '\0' || str[i] == '\10' || str[i] == '\13')
			throw (parameterContainsInvalidCharacterException);
}

void	MessageLexer::validateTrailingString(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '\0' || str[i] == '\10' || str[i] == '\13')
			throw (trailingContainsInvalidCharacterException);
}
