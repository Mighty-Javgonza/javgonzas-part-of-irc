#ifndef INDEXED_REGISTER_KEEPER_HPP
# define INDEXED_REGISTER_KEEPER_HPP

# include "ARegisterKeeper.hpp"

template <class Id, class Register>
class IndexedRegisterKeeper : public ARegisterKeeper<Id, Register>
{
	public:
		typedef typename ARegisterKeeper<Id, Register>::container	container;

		IndexedRegisterKeeper(void) :
			ARegisterKeeper<Id, Register>() {}

		~IndexedRegisterKeeper(void) {}

		bool		Insert(Register const &register_copy) {
			std::pair<Id, Register>
				map_entry(register_copy.Id(), register_copy);

			return this->_Registers().insert(map_entry).second;
		}
	protected:
		typename container::value_type	*_FindRegister(Register const& register_copy) {
			typename container::iterator	it = this->_Registers().begin();

			while (it != this->_Registers().end() && it->second != register_copy)
				it++;
			if (it == this->_Registers().end())
				return NULL;
			return &*it;
		}

		typename container::value_type	*_FindRegister(Id const &id) {
			typename container::iterator	it = this->_Registers().begin();

			while (it != this->_Registers().end() && it->first != id)
				it++;
			if (it == this->_Registers().end())
				return NULL;
			return &*it;
		}

		bool	_RemoveRegister(Id const &id) {
			return this->_Registers().erase(id) != 0;
		}
	private:
};
#endif

