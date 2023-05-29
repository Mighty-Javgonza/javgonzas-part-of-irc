#ifndef REGISTER_NOT_FOUND_HPP
# define REGISTER_NOT_FOUND_HPP

# include <exception>

class RegisterNotFound : public std::exception
{
	public:
		const char	*what(void) const throw();
};
#endif
