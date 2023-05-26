#ifndef I_INDEXED_HPP
# define I_INDEXED_HPP

template <class IdType>
class IIndexed
{
	public:
		virtual IdType const	&Id(void) const = 0;
};
#endif

