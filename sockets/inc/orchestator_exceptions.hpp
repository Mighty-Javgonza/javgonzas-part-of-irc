
#ifndef _ORCHESTATOR_EXCEPTION_HPP_
# define _ORCHESTATOR_EXCEPTION_HPP_

#include "com_exceptions.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

class orchestator_exceptions : public std::exception
{
	private:
		void    fail_poll_sincr();

	public:
		orchestator_exceptions(const int num);
		const char*	what() const throw();

};
#endif
