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
			return ("Invalid nickname");
		}
	} erroneousNicknameException;

	static class ErroneousUserStringException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid user");
		}
	} erroneousUserStringException;

	static class ErroneousChanstringException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid chanstring");
		}
	} erroneousChanstringException;

	static class ErroneousChannelidException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid channel");
		}
	} erroneousChannelidException;

	static class ErroneousChannelException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid channel");
		}
	} erroneousChannelException;

	static class ErroneousIP4Exception : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid IPv4");
		}
	} erroneousIP4Exception;

	static class ErroneousIP6Exception : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid IPv6");
		}
	} erroneousIP6Exception;

	static class ErroneousHostnameException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid hostname");
		}
	} erroneousHostnameException;

	static class ErroneousHostException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid host");
		}
	} erroneousHostException;

	static class ErroneousMsgtoException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid message target");
		}
	} erroneousMsgtoException;

	static class ErroneousMsgtargetException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid message target");
		}
	} erroneousMsgtargetException;

	static class ErroneousTargetException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid target");
		}
	} erroneousTargetException;

	static class ErroneousKeyException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid key");
		}
	} erroneousKeyException;

	static class ErroneousQueryException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid query");
		}
	} erroneousQueryException;

	static class ErroneousMaskException : public std::exception {
		public:
			virtual const char *what() const throw() {
			return ("Invalid mask");
		}
	} erroneousMaskException;
};

#endif
