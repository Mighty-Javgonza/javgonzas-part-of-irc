#ifndef INVALID_ID_HPP
# define INVALID_ID_HPP

# include <exception>

class InvalidId : public std::exception
{
	public:
		const char	*what(void) const throw();
};
#endif
