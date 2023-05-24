#ifndef CHAN_HPP
# define CHAN_HPP

# include "IComparable.hpp"
# include "Client.hpp"
# include "ChanId.hpp"
# include "Key.hpp"
# include "TextMask.hpp"

# include <string>
# include <set>
# include <vector>

class Chan : public IComparable<Chan>, public IIndexed<ChanId>
{
	public:
		static bool	CompareName(Chan const& lhs, std::string const &rhs);

		enum	Mode {
			Anonymous = 0,
			InviteOnly = 1,
			Moderated = 2,
			NoMessages = 3,
			Quiet = 4,
			Private = 5,
			Secret = 6,
			Reop = 7,
			TopicRestricted = 9,
			Limited = 9,
			ChannelKey = 10,
			MODE_SIZE = 11
		};

		Chan(void);
		Chan(std::string const &title, Client &oper);
		Chan(Chan const& rhs);
		virtual ~Chan(void);
		Chan	&operator=(Chan const &rhs);
		bool	operator==(Chan const &rhs) const;
		bool	operator<(Chan const &rhs) const;
		ChanId const &Id(void) const;
		std::string const	&Title(void) const;
		void	Topic(ClientId const& sender, std::string const& topic);
		std::string const	&Topic(void) const;
		void	Join(Client &client);
		void	Leave(ClientId const &sender, Client &target);
		void	LimitMaxSubs(ClientId const& sender, uint64_t limit);
		void	Mode(ClientId const &sender, enum Mode const mode, bool value);
		bool	Mode(enum Mode const mode) const;
		bool	IsChop(ClientId const& cid) const;
		void	Invite(std::string const &nick);
		void	DeleteInvite(std::string const &nick);
		void	ClearInvites(void);
		bool	IsInvited(Client const& client) const;
		bool	IsBanned(ClientId const& cid) const;
		bool	IsFull(void) const;
		bool	IsEmpty(void) const;
		bool	KeyMatches(Key const& key) const;
		void	Chop(ClientId const& sender, ClientId const& target);
		void	Unchop(ClientId const& sender, ClientId const& target);
		std::string	TypedChanstring(void) const;
		bool	IsSubscriptor(ClientId const& cid) const;
		std::vector<ClientId>	*Subscribers(void) const;
	private:
		ChanId								__chan_id;
		std::string						__topic;
		std::string						__title;
		Key										__key;
		std::set<ClientId>		__operators;
		std::set<ClientId>		__subscriptors;
		uint64_t							__max_subscriptions;
		std::vector<bool>			__mode_flags;
		std::vector<TextMask>	__bans;
		std::vector<TextMask>	__ban_exceptions;
		std::vector<TextMask>	__invitations;

		//TODO Exprópiese
		void	__ChopAdd(ClientId const& sender, ClientId const& target);
		void	__ChopDel(ClientId const& sender, ClientId const& target);
};
#endif

