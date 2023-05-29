#ifndef ID_MANAGER_HPP
# define ID_MANAGER_HPP

# include <cstdint>
# include <set>

//TODO a class
//Are the exceptions part of the main class or separate?
# include <exception>
class bad_id_exception : public std::exception {
	public:
		virtual const char	*what(void) const throw() {
			return ("The given ID is not valid.");
		}
};

/*
 *	Provides ID values of a type ID_TYPE.
 *	It can recycle old values.
 *	The max ID value is provided by the maxid function
 *	The min ID is 0
 *	There is a no ID value of TYPE when an ID value could not be provided.
 */

class IdManager {
	public:
		typedef	uintmax_t	ID_TYPE;

		static ID_TYPE	noid(void);
		static ID_TYPE	maxid(void);

		IdManager(void);
		IdManager(IdManager const& im);
		virtual ~IdManager(void);
		IdManager	&operator=(IdManager const& im);

		ID_TYPE		next_id(void);
		void		free_id(ID_TYPE) throw(bad_id_exception);

	private:
		ID_TYPE				_id_count;
		std::set<ID_TYPE>	*_freed_ids;
};
#endif

