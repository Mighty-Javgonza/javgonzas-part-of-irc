/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:30:25 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/17 19:26:32 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_GENERATOR_HPP_
# define _REPLIES_GENERATOR_HPP_

#include "replies.hpp"
#include "user.hpp"
#include "aux_server.hpp"
#include "aux_channel.hpp"
#include <string>
#include <queue>

using namespace std;
class replies_generator : public replies
{
	public:
	std::string welcome(const string& user_nick, const string& server_name, 
			const string& server_version, const string& usr_modes, 
			const string& chann_modes, const string& server_date,
			const string& user_server_name, const string& user_server_version);
	std::string welcome(const string& user_nick, const string& server_name, 
			const string& server_version, const string& usr_modes, const string& chann_modes,
			const string& server_date);
	std::string	admin_ok(const string& server_name, const string& admin_name, 
			const string& admin_nick, const string& admin_email);
	std::string info_rpy(const string& server_info);
	std::string invite_ok(const string& channel_name, const string& user_name);
	std::string invite_away(const string& user_nick, const string& away_msg);
	std::string ison_ok(const string& ison_list);
	std::string join_ok(const string& channel_name, string& channel_topic);
	std::string list_ok(queue<std::pair<const string, const string> > channel_topic);
	std::string mode_us_ok(const string& user_modies);
	std::string mode_ch_ok(const string& channel_name, const string& channel_mode,
			const string& channel_mod_params);
	std::string mode_banlist(const string& channel_ban_list, const string& channel_name);
	std::string mode_exceptlist(const string& channel_excep_list, const string& channel_name);
	std::string mode_invitelist(const string& channel_invite_list, const string& channel_name);
	std::string mode_uniqopis(const string& channel_name, const string& user_nick);
	std::string mode_channelmodeis(const string& channel_name, 
			const string& channel_mode, const string& channel_params);
	std::string motd_ok(const string& server_name, const string& server_motd);
	std::string names_ok(const string& channel_name, const string& channel_names_list);
	std::string oper_ok(void);
	std::string who_ok(const string& who_query, const string& user_name);
	std::string stats_l(const std::string& linkinfo);
	std::string	stats_m(const std::string &command, const std::string &count, const std::string &byte_count, const std::string &remote_count);
	std::string stats_o(const aux_server& server);
	std::string stats_u(const std::string &status_u_string, const std::string &letter);
	std::string	stats_end(const std::string &letter);
	std::string time_ok(const string& server_name, const std::string& hour);
	std::string topic_ok(const string& channel_name, const string& channel_topic);
	std::string topic_no(const string& channel_name);
//	std::string userhost_ok(const aux_server& server);
//	std::string userip_ok(const user& user);
	std::string user_ok(const string& user_reply);
	std::string user_empty(void);
	std::string version_ok(const string& ser_version, const string& ser_debug_lvl,
			const string& ser_name, const string& ser_comment);
	std::string whois_user(const string& user_nick, const string& user_name, 
			const string& user_host, const string& user_real_name);
	std::string whois_channels(const string& user_nick, const string& channel_name);
	std::string whois_away(const string& user_nick, const string& user_away);
	std::string whois_idle(const string& user_pseudo, const string& user_idle, 
			const string& user_signon);
	std::string whois_server(const string& user_pseudo, const string& server_name, 
			const string& server_info);
	std::string whois_operator(const string& user_nick);
	std::string ping_nooring(void);
	// std::string whowas_user(const aux_server& serv, const aux_user& user);
	//---------------------------ERRORS--------------------------------//
	//---------------------------ERRORS--------------------------------//
	//---------------------------ERRORS--------------------------------//
	//---------------------------ERRORS--------------------------------//
	std::string admin_nosuchserver(const string& server_name);
	std::string die_fail(void);
	std::string info_nosuchserver(const string& server_name);
	std::string invite_moreparams(const string& msg);
	std::string invite_nosuchnick(const string& user_nick);
	std::string invite_notonchannel(const string& channel_name);
	std::string invite_useronchannel(const string& user_nick, const string& channel_name);
	std::string invite_chanoprivsneeded(const string& channel_name);
	std::string ison_needmoreparams(void);
	std::string join_needmoreparams(void);
	std::string join_bannedfromchan(const string& channel_name);
	std::string join_inviteonlychan(const string& channel_name);
	std::string join_badchannelkey(const string& msg);
	std::string join_channelisfull(const string& channel_name);
	std::string join_badchanmask(const string& channel_name);
	std::string join_nosuchchannel(const string& str);
	std::string join_toomanychannels(const string& channel_name);
	std::string join_toomanytargets(const string& target);
	std::string join_unavailresource(const string& channel_name);
	std::string kick_needmoreparams(void);
	std::string kick_nosuchchannel(const std::string str);
	std::string kick_badchanmask(const string& channel_name);
	std::string kick_chanoprivsneeded(const string& channel_name);
	std::string kick_notonchannel(const string& channel_name);
	std::string kick_usernotinchannel(const string& user_nick, const string& channel_name);
	std::string kill_noprivileges(void);
	std::string kill_needmoreparams(void);
	std::string kill_nosuchnick(const string& user_nick);
	std::string list_nosuchserver(const string& server_name);
	std::string list_toomanymatches(void);
	std::string names_nosuchserver(const string& server_name);
	std::string names_toomanymatches(void);
	std::string mode_needmoreparams(void);
	std::string mode_chanoprivsneeded(const string& channel_name);
	std::string mode_nosuchnick(const string& user_nick);
	std::string mode_notonchannel(const string& channel_name);
	std::string mode_keyset(const string& channel_name);
	std::string mode_unknownmode(const string& c, const string& channel_name);
	std::string mode_usersdontmatch(void);
	std::string mode_umodeunknownflag(void);
	std::string mode_nochanmodes(const string& channel_name);
	std::string mode_nosuchchannel(const string& str);
	std::string mode_usernotinchannel(const string& user_nick, const string& channel_name);
	std::string motd_nomotd(void);
	std::string nick_nonicknamegiven(void);
	std::string nick_erroneusnickname(const string& user_ncik);
	std::string nick_nicknameinuse(const string& user_nick);
	std::string oper_needmoreparams(void);
	std::string oper_nooperhost(void);
	std::string oper_passwdmismatch(void);
	std::string part_needmoreparams(void);
	std::string part_nosuchchannel(const string& str);
	std::string part_notonchannel(const string& channel_name);
	std::string pass_needmoreparams(void);
	std::string pass_alreadyregistred(void);
	std::string ping_noorigin(void);
	std::string ping_nosuchserver(const std::string& server_name);
	std::string pong_noorigin(void);
	std::string pong_nosuchserver(const std::string& server_name);
	std::string privmsg_norecipient(const string& cmd);
	std::string privmsg_notexttosend(void);
	std::string privmsg_cannotsendtochan(const string& channel_name);
	std::string privmsg_notoplevel(const string& mask);
	std::string privmsg_wildtoplevel(const string& mask);
	//std::string privmsg_toomanytargets(const std::string mask);
	std::string privmsg_nosuchnick(const string& user_nick);
	std::string privmsg_toomanytargets(const string& target);
	std::string stats_nosuchserver(const string& server_name);
	std::string time_nosuchserver(const string& server_name);
	std::string topic_needmoreparams(void);
	std::string topic_notonchannel(const string& channel_name);
	std::string topic_chanoprivsneeded(const string& channel_name);
	std::string topic_nochanmodes(const string& channel_mode);
	std::string user_needmoreparams(void);
	std::string user_alreadyregistred(void);
	std::string userhost_needmoreparams(void);
	std::string users_nosuchserver(const string& server_name);
	std::string users_fileerror(const string& f_o, const string& file);
	std::string users_usersdisabled(void);
	std::string version_nosuchserver(const string& server_name);
	std::string wallops_needmoreparams(void);
	std::string who_nosuchserver(const string& server_name);
	std::string whois_nosuchserver(const string& server_name);
	std::string whois_nonicknamegiven(void);
	std::string whois_nosuchnick(const string& useri_nick);
	std::string whowas_nonicknamegiven(void);
	std::string whowas_wasnosuchnick(const string& user_nick);
	
	public:
	void load_reply_to_users(std::queue<user> &user_list, std::string reply);

};

#endif
