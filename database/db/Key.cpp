#include "Key.hpp"

bool	Key::Match(Key const &lhs, Key const &rhs) {
	return lhs.__key == rhs.__key;
}

Key::Key(void) {}

Key::Key(Key const &rhs) {
	*this = rhs;
}

Key::Key(std::string const& key) : __key(key) {}

Key::~Key(void) {}

Key	&Key::operator=(Key const &rhs)
{
	__key = rhs.__key;
	return (*this);
}

