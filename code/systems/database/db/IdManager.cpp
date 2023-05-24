#include "IdManager.hpp"

#include <limits>

IdManager::IdManager(void) : _id_count(0) {
	_freed_ids = new std::set<ID_TYPE>();
}

IdManager::IdManager(IdManager const& im) {
	_id_count = im._id_count;
	_freed_ids = im._freed_ids;
}

IdManager::~IdManager(void){
	delete _freed_ids;
}

IdManager	&IdManager::operator=(IdManager const& im) {
	delete _freed_ids;
	_freed_ids = im._freed_ids;
	_id_count = im._id_count;
	return *this;
}

IdManager::ID_TYPE	IdManager::noid(void) {
	return std::numeric_limits<IdManager::ID_TYPE>::max();
}

IdManager::ID_TYPE	IdManager::maxid(void) {
	return noid() - 1;
}

IdManager::ID_TYPE	IdManager::next_id(void) {
	IdManager::ID_TYPE	next_id = this->_id_count;

	if (_freed_ids->empty()) {
		if (_id_count == maxid())
			return noid();
		_id_count++;
	} else {
		next_id = *(_freed_ids->begin());
		_freed_ids->erase(next_id);
	}
	return next_id;
}

/*
 *	A valid id is one that has not been given back via free_id()
 *	A valid id can't posssibly be greater or equal than _id_count.
 */
void	IdManager::free_id(ID_TYPE id) throw(bad_id_exception) {
	if (id == noid() || id >= _id_count
			|| _freed_ids->find(id) != _freed_ids->end())
		throw bad_id_exception();
	_freed_ids->insert(id);
}
