#include "TextMask.hpp"

TextMask::TextMask(void) : __mask("") {}

TextMask::TextMask(TextMask const &rhs) : __mask(rhs.__mask) {}

TextMask::TextMask(std::string const &mask) : __mask(mask) {}

TextMask::~TextMask(void) {}

TextMask	&TextMask::operator=(TextMask const &rhs)
{
	__mask = rhs.__mask;
	return *this;
}

bool	TextMask::Pass(std::string const &candidate) const {
	//TODO WE NEED TO IMPLEMENT PROPER WILDCARD EXPANSION/PATTERN-MATCHING
	return __mask == candidate;
}
