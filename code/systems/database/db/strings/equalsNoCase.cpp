#include "caseString.hpp"

bool	equalsNoCase(std::string const& lhs, std::string const& rhs) {
	const size_t	length = lhs.length();
	size_t			pos = 0;

	if (length != rhs.size())
		return false;
	while (pos < length) {
		if (toUpper(lhs[pos]) != toUpper(rhs[pos]))
			return false;
		pos++;
	}
	return true;
}

