class MessageLexer;

#ifndef MESSAGELEXER_HPP
# define MESSAGELEXER_HPP

# include <iostream>

# include "../LexedMessage/LexedMessage.hpp"

class MessageLexer {

public:
	MessageLexer();
	~MessageLexer();

	LexedMessage	lex(std::string);

private:
	void	setAnalysisString(std::string str);
	size_t	analyzed_chars;
	void	setMessagePreffixIfItExists();
	void	putRestOfAnalysisStringInTrailing();
	std::string	getNextWord();
	void	storeParameters();
	void	validateCommandString(std::string str);
	void	validateParameterString(std::string str);
	void	validateTrailingString(std::string str);

	std::string	analysis_string;
	LexedMessage		in_progress_message;



// VVV All exceptions from here  VVV
public:
	class MissingCommandException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The message does not contain a command\n");
		}
	} missingCommandException;

	class PreffixStartsWithSpaceException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: A space was found between preffix and starting ':'\n");
		}
	} preffixStartsWithSpaceException;

	class LetterCommandContainsNonLetterException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The command starts with letter but contains non letter characters\n");
		}
	} letterCommandContainsNonLetterException;

	class EmptyCommandException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The command is empty. A command must contain at least one character\n");
		}
	} emptyCommandException;

	class NumericCommandIsNotThreeDigitsLongException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The command starts with digit but is not three digits long\n");
		}
	} numericCommandIsNotThreeDigitsLongException;

	class NumericCommandContainNonDigitsException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The command starts with digit but contains non digits\n");
		}
	} numericCommandContainNonDigitsException;

	class ParameterContainsInvalidCharacterException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: A parameter contains an invalid character. Invalid characters are: 'NULL', 'CR' and 'LF'\n");
		}
	} parameterContainsInvalidCharacterException;

	class TrailingContainsInvalidCharacterException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: Trailing contains an invalid character. Invalid characters are: 'NULL', 'CR' and 'LF'\n");
		}
	} trailingContainsInvalidCharacterException;
};

#endif
