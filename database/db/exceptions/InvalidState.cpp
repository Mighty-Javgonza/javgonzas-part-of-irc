#include "InvalidState.hpp"

InvalidState::InvalidState(std::string const &message) :
	__message(message) {}

InvalidState::~InvalidState(void) throw() {}

const char	*InvalidState::what(void) const throw() {
	return __message.c_str();
}
