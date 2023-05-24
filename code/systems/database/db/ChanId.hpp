#ifndef CHAN_ID_HPP
# define CHAN_ID_HPP

# include "IComparable.hpp"
# include "exceptions/InvalidId.hpp"

#include <string>

class ChanId : public IComparable<ChanId>
{
	public:
		ChanId(void) throw (InvalidId);
		ChanId(ChanId const &rhs);
		~ChanId(void);
		ChanId	&operator=(ChanId const &rhs);
		bool	operator==(ChanId const &rhs) const;
		bool	operator<(ChanId const &rhs) const;
	private:
		std::string	__id;

		std::string	__tod_to_string(int tod) const throw (InvalidId);

		static int	created_channels;
};
#endif

