#ifndef A_REGISTER_KEEPER_HPP
# define A_REGISTER_KEEPER_HPP

# include "exceptions/RegisterNotFound.hpp"

# include <map>
# include <vector>
# include <algorithm>
# include <stdexcept>

//TODO Other file
template <class MapKey, class MapValue>
MapKey	extractKey(std::pair<const MapKey, MapValue> const& pair) {
	return pair.first;
}

/*
 *	A collection of registers with a const Id. A map.
 *	Id is meant to be the main access tool for any register.
 *	Otherwise it's allowed to search a register using a copy of itself.
 *	RegisterExists allows to check wether a Register exists before calling
 *	to a throw function.
 */

template <class IdType, class RegisterType>
class ARegisterKeeper
{
	public:
		typedef IdType						Id;
		typedef RegisterType				Register;

		ARegisterKeeper(void) {}

		~ARegisterKeeper(void) {}

		bool	Remove(Id const &id) {
			return _RemoveRegister(id);
		}

		bool	IdExists(Id const& id_copy) {
			return __registers.find(id_copy) != __registers.end();
		}

		template <class T>
		bool	RegisterExists(T const& to_find,
				bool (*cmpFunct)(Register const&, T const&)) {
			typename container::iterator target = __registers.begin();
			while (target != __registers.end()
					&& !cmpFunct(target->second, to_find))
				target++;
			return target != __registers.end();
		}

		bool	RegisterExists(Register const& register_copy) {
			typename container::iterator target = __registers.begin();
			while (target != __registers.end()
					&& target->second != register_copy)
				target++;
			return target != __registers.end();
		}

		template <class T>
		const Id	&IdOf(T const& to_find,
				bool (*cmpFunct)(Register const&, T const&))
				throw (RegisterNotFound) {
			typename container::iterator target = __registers.begin();
			while (target != __registers.end()
					&& !cmpFunct(target->second, to_find))
				target++;
			if (target == __registers.end())
				throw RegisterNotFound();
			return target->first;
		}

		const Id	&IdOf(Register const &register_copy)
				throw (RegisterNotFound) {
			typename container::iterator target = __registers.begin();
			while (target != __registers.end()
					&& target->second == register_copy)
				target++;
			if (target == __registers.end())
				throw RegisterNotFound();
			return target->first;
		}

		Register	&Find(Id const &id) throw (std::out_of_range) {
			typename container::iterator target = __registers.find(id);
			if (target == __registers.end())
				throw std::out_of_range("");
			return target->second;
		}

		std::vector<Id>	*Vector(void) {
			std::vector<Id>	*all_ids = new std::vector<Id>(_Registers().size());

			transform(_Registers().begin(), _Registers().end(),
					all_ids->begin(), extractKey<Id, Register>);
			return all_ids;
		}
		
		unsigned int	Size(void) const {
			return _Registers().size();
		}

		virtual bool	Insert(Register const &register_copy) = 0;
	protected:
		typedef std::map<Id, Register>			container;

		virtual bool	_RemoveRegister(Id const &id) = 0;

		const container	&_Registers(void) const {
			return __registers;
		}

		container	&_Registers(void) {
			return __registers;
		}
	private:
		container	__registers;
};
#endif

