class MessageParameterValidator;

#ifndef MESSAGEPARAMETERVALIDATOR_HPP
# define MESSAGEPARAMETERVALIDATOR_HPP

# include <iostream>

class MessageParameterValidator {

public:
	MessageParameterValidator();
	~MessageParameterValidator();

	static void	validate_nickname(std::string str);
	static bool	is_special_char(char c);

public:

	static class ErroneousNicknameException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The command specified requires more parameters\n");
		}
	} erroneousNicknameException;

};

#endif
