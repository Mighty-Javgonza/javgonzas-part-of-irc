#include "strings/caseString.hpp"
#include "ClientData.hpp"

bool	ClientData::CompareUserHost(ClientData const& lhs,
		std::string const &rhs) {
	return equalsNoCase(lhs.Id().FullHostname(), rhs);
}
bool	ClientData::CompareNick(ClientData const& lhs, std::string const &rhs) {
	return equalsNoCase(lhs._nickname, rhs);
}

bool	ClientData::CompareFd(ClientData const& lhs, int const &rhs) {
	return (lhs.Id().Fd() == rhs);
}

ClientData::ClientData(void) :
	_id(ClientId()),
	_nickname(""),
	_realname(""),
	_mode_flags(MODE_SIZE, false) {}

ClientData::ClientData(ClientId const &rhs) :
	_id(ClientId(rhs)),
	_nickname(""),
	_realname(""),
	_mode_flags(MODE_SIZE, false) {}

ClientData::ClientData(ClientData const &rhs) :
	user_times(rhs.user_times),
	msg_in(rhs.msg_in),
	msg_out(rhs.msg_out),
	_id(rhs._id),
	_nickname(rhs._nickname),
	_realname(rhs._realname),
	_mode_flags(rhs._mode_flags) {}

ClientData::~ClientData(void) {}

ClientData	&ClientData::operator=(ClientData const &rhs) {
	user_times = rhs.user_times;
	msg_in = rhs.msg_in;
	msg_out = rhs.msg_out;
	_nickname = rhs._nickname;
	_realname = rhs._realname;
	_id = rhs._id;
	return *this;
}

bool	ClientData::operator==(ClientData const &rhs) const {
	return _id == rhs._id;
}

bool	ClientData::operator<(ClientData const &rhs) const {
	return _id < rhs._id;
}
void	ClientData::operator<<(std::string const &message) {
	messages_sent += 1;
	kilobytes_sent += message.length();
	msg_out.add_msg(message);
}

ClientId const	&ClientData::Id(void) const {
	return _id;
}

void	ClientData::Nick(std::string const& nick) {
	_nickname = nick;
}

const std::string	&ClientData::Nick(void) const {
	return _nickname;
}

void	ClientData::Name(std::string const& name) {
	_realname = name;
}

const std::string	&ClientData::Name(void) const {
	return _realname;
}

std::string	ClientData::MessagePrefix(void) const throw (InvalidState) {
	if (Nick() == "")
		throw InvalidState("Client missing nickname");
	std::string	prefix = Nick() + "!" + _id.FullHostname();

	return (prefix);
}

bool	ClientData::Mode(UserMode const mode) const {
	return _mode_flags[mode];
}

void	ClientData::Mode(UserMode const mode, bool value) {
	_mode_flags[mode] = value;
}

std::string	ClientData::ModeString(void) const {
	std::string	active_modes = "";
	if (Mode(Invisible))
		active_modes += "i";
	if (Mode(ServerNotice))
		active_modes += "s";
	if (Mode(Wallops))
		active_modes += "w";
	if (Mode(Operator))
		active_modes += "o";
	if (Mode(LocalOperator))
		active_modes += "O";
	if (Mode(Wallops))
		active_modes += "w";
	return (active_modes);
}
bool	ClientData::IsOp(void) const
{
	return (Mode(LocalOperator) || Mode(Operator));
}
