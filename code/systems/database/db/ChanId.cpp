#include "ChanId.hpp"

int ChanId::created_channels = 0;

ChanId::ChanId(void) throw (InvalidId) :
		__id(__tod_to_string(created_channels))
	{ created_channels++;}

ChanId::ChanId(ChanId const &rhs) {
	__id = rhs.__id;
}

ChanId::~ChanId(void) {}

ChanId	&ChanId::operator=(ChanId const &rhs) {
	__id = rhs.__id;
	return *this;
}

bool	ChanId::operator==(ChanId const &rhs) const {
	return __id.compare(rhs.__id) == 0;
}

bool	ChanId::operator<(ChanId const &rhs) const {
	return __id.compare(rhs.__id) < 0;
}

std::string	ChanId::__tod_to_string(int tod) const throw (InvalidId) {
	if (tod <= -1)
		throw InvalidId();

	const std::string	base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	const size_t		base_lenght = base.size();
	std::string	number("");
	while (tod > 0) {
		number.push_back(base[tod % base_lenght]);
		tod /= base_lenght;
	}
	if (number.size() < 5)
		number.insert(number.begin(), 5 - number.size(), 'A');
	return number;
}
