class MessageParameterValidator;

#ifndef MESSAGEPARAMETERVALIDATOR_HPP
# define MESSAGEPARAMETERVALIDATOR_HPP

# include <iostream>

class MessageParameterValidator {

public:
	MessageParameterValidator();
	~MessageParameterValidator();

	static void	validate_nickname(std::string str);
	static void	validate_user(std::string str);
	static void	validate_chanstring(std::string str);
	static void	validate_channelid(std::string str);
	static void	validate_ipv4(std::string str);
	static void	validate_ipv6(std::string str);
	static void	validate_hostaddr(std::string str);
	static void	validate_hostname(std::string str);
	static void	validate_host(std::string str);
	static void	validate_key(std::string str);
	static void	validate_mask(std::string str);
	static bool	is_shortname(std::string str);
	static bool	is_special_char(char c);
	static bool	is_hexdigit(char c);

public:

	static class ErroneousNicknameException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The nickname provided does not follow the naming rules\n");
		}
	} erroneousNicknameException;

	static class ErroneousUserStringException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The user provided does not follow the naming rules\n");
		}
	} erroneousUserStringException;

	static class ErroneousChanstringException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The chanstring contains forbidden characters\n");
		}
	} erroneousChanstringException;

	static class ErroneousChannelidException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The channelid provided does not follow the naming rules\n");
		}
	} erroneousChannelidException;

	static class ErroneousChannelException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The channelid provided does not follow the naming rules\n");
		}
	} erroneousChannelException;

	static class ErroneousIP4Exception : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The ipv4 provided does not follow the parsing rules\n");
		}
	} erroneousIP4Exception;

	static class ErroneousIP6Exception : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The ipv6 provided does not follow the parsing rules\n");
		}
	} erroneousIP6Exception;

	static class ErroneousHostnameException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The hostname provided does not follow the naming rules\n");
		}
	} erroneousHostnameException;

	static class ErroneousHostException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The host provided does not follow the naming rules\n");
		}
	} erroneousHostException;

	static class ErroneousMsgtoException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The msgto provided does not follow the naming rules\n");
		}
	} erroneousMsgtoException;

	static class ErroneousMsgtargetException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The msgtarget provided does not follow the naming rules\n");
		}
	} erroneousMsgtargetException;

	static class ErroneousTargetException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The target provided does not follow the naming rules\n");
		}
	} erroneousTargetException;

	static class ErroneousKeyException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The key provided does not follow the naming rules\n");
		}
	} erroneousKeyException;

	static class ErroneousQueryException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The query provided does not follow the naming rules\n");
		}
	} erroneousQueryException;

	static class ErroneousMaskException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("ERROR: The mask provided does not follow the naming rules\n");
		}
	} erroneousMaskException;
};

#endif
