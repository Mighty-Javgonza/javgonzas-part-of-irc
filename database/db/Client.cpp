#include "Client.hpp"

//IRC RFC Suggests using a max channel subs value of 10.
unsigned int	Client::__max_chans = 10;

bool	Client::CompareUserHost(Client const& lhs, std::string const &rhs) {
	return ClientData::CompareUserHost(lhs, rhs);
}

bool	Client::CompareNick(Client const& lhs, std::string const& rhs) {
	return ClientData::CompareNick(lhs, rhs);
}

bool	Client::CompareFd(Client const& lhs, int const& rhs) {
	return ClientData::CompareFd(lhs, rhs);
}

Client::Client(void) {}

Client::Client(Client const& rhs) :
	ClientData(rhs),
	__subscriptions(rhs.__subscriptions) {}

Client::Client(ClientData const& rhs) :
	ClientData(rhs) {}

Client::~Client(void) {}

Client	&Client::operator=(Client const& rhs) {
	ClientData::operator=(rhs);
	__subscriptions = rhs.__subscriptions;
	return *this;
}

bool	Client::Join(ChanId const& cid) {
	if (__subscriptions.size() >= __max_chans)
		return false;
	return __subscriptions.insert(cid).second;
}

void	Client::Leave(ChanId const& cid) {
	__subscriptions.erase(cid);
}

std::vector<ChanId>	*Client::Subscriptions(void) const {
	return new std::vector<ChanId>(__subscriptions.begin(), __subscriptions.end());
}

bool	Client::CanQuit(void) const{
	return __subscriptions.size() == 0;
}
