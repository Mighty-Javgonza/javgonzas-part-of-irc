#include "Unregistered.hpp"

bool	Unregistered::CompareNick(Unregistered const& lhs,
		std::string const &rhs) {
	return ClientData::CompareNick(lhs, rhs);
}

bool	Unregistered::CompareFd(Unregistered const& lhs, int const &rhs) {
	return ClientData::CompareFd(lhs, rhs);
}

Unregistered::Unregistered(void) :
	ClientData(),
	__valid_pass(false) {}

Unregistered::Unregistered(ClientId const &id, bool valid_pass) :
	ClientData(id),
	__valid_pass(valid_pass) {}

Unregistered::Unregistered(Unregistered const &rhs) :
	ClientData(rhs),
	__valid_pass(rhs.__valid_pass) {}

Unregistered::~Unregistered(void) {}

Unregistered	&Unregistered::operator=(Unregistered const &rhs) {
	ClientData::operator=(rhs);
	return *this;
}

//	Pass validation starts the registration process.
void	Unregistered::ValidatePass(void) {
	if (!__valid_pass) {
		__valid_pass = true;
		Nick("");
		Name("");
	}
}

bool	Unregistered::IsReady(void) const {
	return __valid_pass && Nick() != "" && Name() != "";
}
