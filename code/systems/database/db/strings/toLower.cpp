#include "caseString.hpp"

char	toLower(char c) {
	if (std::string("{|}").find(c) != std::string::npos)
		return c + 0x20;
	return std::toupper(c);
}

