#ifndef INVALID_STATE_HPP
# define INVALID_STATE_HPP

# include <string>
# include <exception>

class InvalidState : public std::exception
{
	public:
		InvalidState(std::string const &message);
		~InvalidState(void) throw();
		const char	*what(void) const throw();
	private:
		std::string	__message;
};
#endif
