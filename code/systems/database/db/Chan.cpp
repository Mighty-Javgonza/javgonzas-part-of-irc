#include "Chan.hpp"
#include "strings/caseString.hpp"

bool	Chan::CompareName(Chan const& lhs, std::string const &rhs) {
	return equalsNoCase(lhs.Title(), rhs);
}

Chan::Chan(void) {}

Chan::Chan(std::string const &title, Client &oper) :
		__chan_id(ChanId()),
		__topic(""),
		__title(title),
		__key(Key()),
		__operators(std::set<ClientId>()),
		__subscriptors(std::set<ClientId>()),
		__max_subscriptions(0),
		__mode_flags(std::vector<bool>(Chan::MODE_SIZE, false)),
		__bans(std::vector<TextMask>()),
		__ban_exceptions(std::vector<TextMask>()),
		__invitations(std::vector<TextMask>()) {
	Join(oper);
	__operators.insert(oper.Id());
}

Chan::Chan(Chan const& rhs) {
	*this = rhs;
}

Chan::~Chan(void) {}

Chan	&Chan::operator=(Chan const &rhs) {
	__topic = rhs.__topic;
	__chan_id = rhs.__chan_id;
	__title = rhs.__title;
	__key = rhs.__key;
	__operators = rhs.__operators;
	__subscriptors = rhs.__subscriptors;
	__max_subscriptions = rhs.__max_subscriptions;
	__mode_flags = rhs.__mode_flags;
	__bans = rhs.__bans;
	__ban_exceptions = rhs.__ban_exceptions;
	__invitations = rhs.__invitations;
	return *this;
}

bool	Chan::operator==(Chan const &rhs) const {
	return equalsNoCase(__title, rhs.__title);
}

bool	Chan::operator<(Chan const &rhs) const {
	return __title.compare(rhs.__title) < 0;
}

ChanId const	&Chan::Id(void) const {
	return __chan_id;
}

std::string const	&Chan::Title(void) const {
	return __title;
}

void	Chan::Topic(ClientId const& sender, std::string const& topic) {
	if (!Mode(TopicRestricted) || IsChop(sender))
		__topic = topic;
}

std::string const	&Chan::Topic(void) const {
	return __topic;
}

void	Chan::Join(Client &client) {
	if (__subscriptors.insert(client.Id()).second) {
		if (!client.Join(__chan_id))
			__subscriptors.erase(client.Id());
	}
}

void	Chan::Leave(ClientId const& sender, Client & target) {
	if (sender != target && !IsChop(sender))
		return ;
	if (__subscriptors.count(target.Id()) == 0)
		return ;
	target.Leave(Id());
	__ChopDel(sender, target.Id());
	__subscriptors.erase(target.Id());
}

void	Chan::LimitMaxSubs(ClientId const& sender, uint64_t limit) {
	if (IsChop(sender))
		__max_subscriptions = limit;
}

void	Chan::Mode(ClientId const &sender, enum Mode const mode, bool value) {
	if (!IsChop(sender))
		return ;
	__mode_flags[mode] = value;
}

bool	Chan::Mode(enum Mode const mode) const {
	return __mode_flags[mode];
}

std::string	Chan::ModeString(void) const {
	std::string	flags("+");

	char mode_c;
	for(int i = 0; i < MODE_SIZE; i++) {
		if (Mode(static_cast<enum Mode>(i))) {
			switch (i) {
				case Anonymous:
					mode_c = 'a';
					break;
				case InviteOnly:
					mode_c = 'i';
					break;
				case Moderated:
					mode_c = 'm';
					break;
				case NoMessages:
					mode_c = 'n';
					break;
				case Quiet:
					mode_c = 'q';
					break;
				case Private:
					mode_c = 'p';
					break;
				case Secret:
					mode_c = 's';
					break;
				case Reop:
					mode_c = 'r';
					break;
				case TopicRestricted:
					mode_c = 't';
					break;
				case Limited:
					mode_c = 'l';
					break;
				default:
					mode_c = 'k';
			}
			flags.push_back(mode_c);
		}
	}
	if (flags.size() == 1)
		return "";
	return flags;
}

bool	Chan::IsChop(ClientId const& cid) const {
	return __operators.count(cid) == 1;
}

bool	Chan::IsBanned(ClientId const& cid) const {
	for (std::vector<TextMask>::const_iterator exception = __ban_exceptions.begin();
			exception != __ban_exceptions.end();
			exception++) {
		if (exception->Pass(cid.FullHostname()))
			return false;
	}
	for (std::vector<TextMask>::const_iterator ban = __bans.begin();
			ban != __bans.end();
			ban++) {
		if (ban->Pass(cid.FullHostname()))
			return true;
	}
	return false;
}

void	Chan::Invite(std::string const &nick) {
	__invitations.insert(__invitations.end(), TextMask(nick));
}

void	Chan::DeleteInvite(std::string const &nick) {
	std::vector<TextMask>::const_iterator invite_mask = __invitations.begin();
	while (invite_mask != __invitations.end() && !invite_mask->Pass(nick)) {
			invite_mask++;
	}
}

void	Chan::ClearInvites(void) {
	__invitations.clear();
}

bool	Chan::IsInvited(Client const& client) const {
	for (std::vector<TextMask>::const_iterator invite_mask = __invitations.begin();
			invite_mask != __invitations.end();
			invite_mask++) {
		if (invite_mask->Pass(client.Nick()))
			return true;
	}
	return false;
}

bool	Chan::IsFull(void) const {
	if (Mode(Limited))
		return __subscriptors.size() >= __max_subscriptions;
	return false;
}

bool	Chan::IsEmpty(void) const {
	return __subscriptors.size() == 0;
}

bool	Chan::KeyMatches(Key const& key) const {
	if (Mode(ChannelKey))
		return Key::Match(__key, key);
	return true;
}

void	Chan::Chop(ClientId const& sender, ClientId const& target) {
	if (!IsChop(sender))
		return ;
	__operators.insert(target);
}

void	Chan::Unchop(ClientId const& sender, ClientId const& target) {
	if (!IsChop(sender))
		return ;
	__operators.erase(target);
}

std::string	Chan::TypedChanstring(void) const {
	if (Mode(Secret))
		return ("@" + __title);
	else if (Mode(Private))
		return ("*" + __title);
	else
		return ("=" + __title);
}

bool	Chan::IsSubscriptor(ClientId const& cid) const {
	return __subscriptors.find(cid) != __subscriptors.end();
}

std::vector<ClientId>	*Chan::Subscribers(void) const {
	return new std::vector<ClientId>(__subscriptors.begin(), __subscriptors.end());
}

//Son Necesarios? Se usan?? vvvv TODO
void Chan::__ChopAdd(ClientId const& sender, ClientId const& target) {
	if (IsChop(sender) && __subscriptors.count(target) > 0)
		__operators.insert(target);
}

void	Chan::__ChopDel(ClientId const& sender, ClientId const& target) {
	if (IsChop(sender) && __subscriptors.count(target) > 0)
		__operators.erase(target);
}
