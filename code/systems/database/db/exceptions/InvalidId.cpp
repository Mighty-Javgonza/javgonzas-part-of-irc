#include "InvalidId.hpp"

const char	*InvalidId::what(void) const throw () {
	return "Id given not valid.";
}
