/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies_generator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:52:09 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/17 20:06:10 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replies_generator.hpp"

std::string replies_generator::welcome(const string& user_nick, const string& server_name, 
		const string& server_version, const string& usr_modes, 
		const string& chann_modes, const string& server_date,
		const string& user_server_name, const string& user_server_version)
{
	std::string	answ;
	
	answ.append(generate_msg(001, user_nick, "", "", ""));
	answ.append(generate_msg(002, user_server_name, user_server_version, "", ""));
	answ.append(generate_msg(003, server_date, "", "", ""));
	answ.append(generate_msg(004, server_name, server_version, usr_modes, chann_modes));
	return answ;
}

std::string	replies_generator::admin_ok(const string& server_name, const string& admin_name, 
		const string& admin_nick, const string& admin_email)
{
	std::string	answ;

	answ.append(generate_msg(256, server_name, "", "", ""));
	answ.append(generate_msg(257, admin_name, "", "", ""));
	answ.append(generate_msg(258, admin_nick, "", "", ""));
	answ.append(generate_msg(259, admin_email, "", "", ""));
	return answ;
}

std::string replies_generator::info_rpy(const string& server_info)
{
	std::string answ;

	answ.append(generate_msg(371, server_info, "", "", ""));
	answ.append(generate_msg(374, "", "", "", ""));
	return answ;
}

std::string replies_generator::invite_ok(const string& channel_name, const string& user_name)
{
	return(generate_msg(341, channel_name, user_name, "", ""));
}

std::string replies_generator::invite_away(const string& user_nick, const string& away_msg)
{
	return (generate_msg(301, user_nick, away_msg, "", ""));
}

std::string replies_generator::ison_ok(const string& ison_list)
{
	return (generate_msg(303, ison_list, "", "", ""));
}

std::string replies_generator::join_ok(const string& channel_name, string& channel_topic)
{
	return(generate_msg(332, channel_name, channel_topic, "", ""));
}

std::string replies_generator::list_ok(queue<std::pair<const string, const string> > channel_topic)
{
	std::string answ;

	while (!channel_topic.empty())
	{
		answ.append(generate_msg(322, channel_topic.front().first, channel_topic.front().second, "", ""));
		channel_topic.pop();
	}
	answ.append(generate_msg(323, "", "", "", ""));
	return answ;
}

std::string replies_generator::mode_us_ok(const string& user_modies)
{
	return(generate_msg(221, user_modies, "", "", ""));
}

std::string replies_generator::mode_ch_ok(const string& channel_name, const string& channel_mode,
			const string& channel_mod_params)
{
	return (generate_msg(324, channel_name, channel_mode, channel_mod_params, ""));
}

std::string replies_generator::mode_banlist(const string& channel_ban_list, const string& channel_name)
{
	std::string answ;
	answ.append(generate_msg(367, channel_ban_list, "", "", ""));
	answ.append(generate_msg(368, channel_name, "", "", ""));
	return answ;
}

std::string replies_generator::mode_exceptlist(const string& channel_excep_list, const string& channel_name)
{
	std::string answ;
	answ.append(generate_msg(348, channel_name, channel_excep_list,	"", ""));
	answ.append(generate_msg(349, channel_name, "", "", ""));
	return(answ);
}

std::string replies_generator::mode_invitelist(const string& channel_invite_list, const string& channel_name)
{
	std::string answ;
	answ.append(generate_msg(346, channel_name, channel_invite_list,	"", ""));
	answ.append(generate_msg(347, channel_name, "", "", ""));
	return(answ);
}

std::string replies_generator::mode_uniqopis(const string& channel_name, const string& user_nick)
{
	return(generate_msg(325, channel_name, user_nick, "", ""));
}

std::string replies_generator::mode_channelmodeis(const string& channel_name, 
		const string& channel_mode, const string& channel_params)
{
	return(generate_msg(324, channel_name, channel_mode, channel_params, ""));
}

std::string replies_generator::motd_ok(const string& server_name, const string& server_motd)
{
	std::string answ;
	answ.append(generate_msg(375, server_name, "", "", ""));
	answ.append(generate_msg(372, server_motd, "", "", ""));
	answ.append(generate_msg(376, "", "", "", ""));
	return(answ);
}

std::string replies_generator::names_ok(const string& channel_name, const string& channel_names_list)
{
	std::string answ;
	answ.append(generate_msg(353, channel_name, channel_names_list, "", ""));
	answ.append(generate_msg(366, channel_name, "", "", ""));
	return(answ);
}

std::string replies_generator::oper_ok()
{
	return(generate_msg(381, "", "", "", ""));
}

std::string replies_generator::who_ok(const string& who_query, const string& user_name)
{
	std::string answ;
	answ.append(generate_msg(352, who_query, "", "", ""));
	answ.append(generate_msg(315, user_name, "", "", ""));
	return(answ);
}

std::string replies_generator::stats_l(const std::string& linkinfo)
{
	std::string answ;
	answ.append(generate_msg(211, linkinfo, "", "", ""));
	return(answ);
}

std::string replies_generator::stats_m(const std::string &command, const std::string &count, const std::string &byte_count, const std::string &remote_count)
{
	std::string answ;
	answ.append(generate_msg(212, command, count, byte_count, remote_count));
	return(answ);
}

std::string replies_generator::stats_end(const std::string &letter)
{
	std::string answ;
	answ.append(generate_msg(219, letter, "", "", ""));
	return(answ);
}

std::string replies_generator::stats_o(const aux_server& server)
{
	std::string answ;
	answ.append(generate_msg(212, server.get_stats_o(), "", "", ""));
	answ.append(generate_msg(219, server.get_stats_letter(), "", "", ""));
	return(answ);
}

std::string replies_generator::stats_u(const std::string &stats_u_string, const std::string &letter)
{
	std::string answ;
	answ.append(generate_msg(242, stats_u_string, "", "", ""));
	answ.append(generate_msg(219, letter, "", "", ""));
	return(answ);
}

std::string replies_generator::time_ok(const string& server_name, const std::string& hour)
{
	return(generate_msg(391, server_name, hour, "", ""));
}

std::string replies_generator::topic_ok(const string& channel_name, const string& channel_topic)
{
	return(generate_msg(332, channel_name, channel_topic, "", ""));
}

std::string replies_generator::topic_no(const string& channel_name)
{
	return(generate_msg(331, channel_name, "", "", ""));
}

//std::string replies_generator::userhost_ok(const aux_server& server)
//{
//	return(generate_msg(302, server.get_userhost_rpy(), "", "", ""));
//}

//std::string replies_generator::userip_ok(const user& user)
//{
//	return(generate_msg(392, user.get_nickname(), user.get_ip(), "", ""));
//}

std::string replies_generator::user_ok(const string& user_reply)
{
	std::string	answ;
	answ.append(generate_msg(392, "", "", "", ""));
	answ.append(generate_msg(393, user_reply, "", "", ""));
	answ.append(generate_msg(394, "", "", "", ""));
	return(answ);
}

std::string replies_generator::user_empty(void)
{
	return(generate_msg(395, "", "", "", ""));
}

std::string replies_generator::version_ok(const string& ser_version, const string& ser_debug_lvl,
			const string& ser_name, const string& ser_comment)
{
	return(generate_msg(351, ser_version, ser_debug_lvl, ser_name, ser_comment));
}

std::string replies_generator::whois_user(const string& user_nick, const string& user_name, 
			const string& user_host, const string& user_real_name)
{	
	return(generate_msg(311, user_nick, user_name, user_host, user_real_name));
}

std::string replies_generator::whois_channels(const string& user_nick, const string& channel_name)
{
	return(generate_msg(319, user_nick, channel_name, "", ""));
}

std::string replies_generator::whois_away(const string& user_nick, const string& user_away)
{
	return(generate_msg(301, user_nick,	user_away, "", ""));
}
	
std::string replies_generator::whois_idle(const string& user_pseudo, const string& user_idle, 
			const string& user_signon)
{
	return(generate_msg(317, user_pseudo, user_idle, user_signon, ""));
}

std::string replies_generator::whois_server(const string& user_pseudo, const string& server_name, 
			const string& server_info)
{
	return(generate_msg(312, user_pseudo, server_name, server_info, ""));
}

std::string replies_generator::whois_operator(const string& user_nick)
{
	return(generate_msg(313, user_nick, "", "", ""));
}

	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//-----------------ERRORS----------------------//
	//
std::string replies_generator::admin_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::die_fail(void)
{
	return(generate_msg(481, "", "", "", ""));
}

std::string replies_generator::info_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::invite_moreparams(const string& msg)
{
	return(generate_msg(461, msg, "", "", ""));
}

std::string replies_generator::invite_nosuchnick(const string& user_nick)
{
	return(generate_msg(401, user_nick, "", "", ""));
}

std::string replies_generator::invite_notonchannel(const string& channel_name)
{
	return(generate_msg(442, channel_name, "", "", ""));
}

std::string replies_generator::invite_useronchannel(const string& user_nick, const string& channel_name)
{
	return(generate_msg(441, user_nick, channel_name, "", ""));
}

std::string replies_generator::invite_chanoprivsneeded(const string& channel_name)
{
	return(generate_msg(482, channel_name, "", "", ""));
}

std::string replies_generator::ison_needmoreparams()
{
	return(generate_msg(461, "ISON", "", "", ""));
}

std::string replies_generator::join_needmoreparams()
{
	return(generate_msg(461, "JOIN", "", "", ""));
}

std::string replies_generator::join_bannedfromchan(const string& channel_name)
{
	return(generate_msg(474, channel_name, "", "", ""));
}

std::string replies_generator::join_inviteonlychan(const string& channel_name)
{
	return(generate_msg(473, channel_name, "", "", ""));
}

std::string replies_generator::join_badchannelkey(const string& msg)
{
	return(generate_msg(475, msg, "", "", ""));
}

std::string replies_generator::join_channelisfull(const string& channel_name)
{
	return(generate_msg(471, channel_name, "", "", ""));
}

std::string replies_generator::join_badchanmask(const string& channel_name)
{
	return(generate_msg(471, channel_name, "", "", ""));
}

std::string replies_generator::join_nosuchchannel(const string& str)
{
	return(generate_msg(403, str, "", "", ""));
}

std::string replies_generator::join_toomanychannels(const string& channel_name)
{
	return(generate_msg(405, channel_name, "", "", ""));
}

std::string replies_generator::join_toomanytargets(const string& target)
{
	return(generate_msg(407, target, "", "", ""));
}

std::string replies_generator::join_unavailresource(const string& channel_name)
{
	return(generate_msg(437, channel_name, "", "", ""));
}

std::string replies_generator::kick_needmoreparams()
{
	return(generate_msg(461, "KICK", "", "", ""));
}

std::string replies_generator::kick_nosuchchannel(const std::string str)
{
	return(generate_msg(403, str, "", "", ""));
}

std::string replies_generator::kick_badchanmask(const string& channel_name)
{
	return(generate_msg(476, channel_name, "", "", ""));
}

std::string replies_generator::kick_chanoprivsneeded(const string& channel_name)
{
	return(generate_msg(482, channel_name, "", "", ""));
}

std::string replies_generator::kick_notonchannel(const string& channel_name)
{
	return(generate_msg(442, channel_name, "", "", ""));
}	

std::string replies_generator::kick_usernotinchannel(const string& user_nick, const string& channel_name)
{
	return(generate_msg(441, user_nick, channel_name, "", ""));
}

std::string replies_generator::kill_noprivileges(void)
{
	return(generate_msg(481, "", "", "", ""));
}

std::string replies_generator::kill_needmoreparams()
{
	return(generate_msg(461, "KILL", "", "", ""));
}

std::string replies_generator::kill_nosuchnick(const string& user_nick)
{
	return(generate_msg(401, user_nick, "", "", ""));
}
	
std::string replies_generator::list_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::list_toomanymatches()
{
	return(generate_msg(503, "", "", "", ""));
}
	
std::string replies_generator::names_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::names_toomanymatches()
{
	return(generate_msg(503, "", "", "", ""));
}
std::string replies_generator::mode_needmoreparams()
{
	return(generate_msg(461, "MODE", "", "", ""));
}

std::string replies_generator::mode_chanoprivsneeded(const string& channel_name)
{
	return(generate_msg(482, channel_name, "", "", ""));
}

std::string replies_generator::mode_nosuchnick(const string& user_nick)
{
	return(generate_msg(401, user_nick, "", "", ""));
}

std::string replies_generator::mode_notonchannel(const string& channel_name)
{
	return(generate_msg(442, channel_name, "", "", ""));
}

std::string replies_generator::mode_keyset(const string& channel_name)
{
	return(generate_msg(467, channel_name, "", "", ""));
}

std::string replies_generator::mode_unknownmode(const string& c, const string& channel_name)
{
	return(generate_msg(472, c, channel_name, "", ""));
}

std::string replies_generator::mode_nosuchchannel(const string& str)
{
	return(generate_msg(403, str, "", "", ""));
}
	
std::string replies_generator::mode_usersdontmatch(void)
{
	return(generate_msg(502, "", "", "", ""));
}

std::string replies_generator::mode_umodeunknownflag(void)
{
	return(generate_msg(501, "", "", "", ""));
}

std::string replies_generator::mode_nochanmodes(const string& channel_name)
{
	return(generate_msg(477, channel_name, "", "", ""));
}

std::string replies_generator::mode_usernotinchannel(const string& user_nick, const string& channel_name)
{
	return(generate_msg(441, user_nick, channel_name, "", ""));
}

std::string replies_generator::motd_nomotd(void)
{
	return(generate_msg(422, "", "", "", ""));
}

std::string replies_generator::nick_nonicknamegiven(void)
{
	return(generate_msg(431, "", "", "", ""));
}

std::string replies_generator::nick_erroneusnickname(const string& user_nick)
{
	return(generate_msg(432, user_nick, "", "", ""));
}

std::string replies_generator::nick_nicknameinuse(const string& user_nick)
{
	return(generate_msg(433, user_nick, "", "", ""));
}

std::string replies_generator::oper_needmoreparams()
{
	return(generate_msg(461, "OPER", "", "", ""));
}

std::string replies_generator::oper_nooperhost(void)
{
	return(generate_msg(491, "", "", "", ""));
}

std::string replies_generator::oper_passwdmismatch(void)
{
	return(generate_msg(464, "", "", "", ""));
}

std::string replies_generator::part_needmoreparams()
{
	return(generate_msg(461, "PART", "", "", ""));
}

std::string replies_generator::part_nosuchchannel(const string& str)
{
	return(generate_msg(403, str, "", "", ""));
}

std::string replies_generator::part_notonchannel(const string& channel_name)
{
	return(generate_msg(442, channel_name, "", "", ""));
}

//std::string replies_generator::mode_nochanmodes(const aux_channel& channel)
//{
//	return(generate_msg(442, channel.get_name(), "", "", ""));
//}	

std::string replies_generator::pass_needmoreparams()
{
	return(generate_msg(461, "PASS", "", "", ""));
}

std::string replies_generator::pass_alreadyregistred(void)
{
	return(generate_msg(462, "", "", "", ""));
}

std::string replies_generator::ping_noorigin(void)
{
	return(generate_msg(409, "", "", "", ""));
}

std::string replies_generator::ping_nosuchserver(const std::string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::pong_noorigin(void)
{
	return(generate_msg(409, "", "", "", ""));
}

std::string replies_generator::pong_nosuchserver(const std::string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::privmsg_norecipient(const string& cmd)
{
	return(generate_msg(411, cmd, "", "", ""));
}

std::string replies_generator::privmsg_notexttosend(void)
{
	return(generate_msg(411, "", "", "", ""));
}

std::string replies_generator::privmsg_cannotsendtochan(const string& channel_name)
{
	return(generate_msg(404, channel_name, "", "", ""));
}

std::string replies_generator::privmsg_notoplevel(const string& mask)
{
	return(generate_msg(413, mask, "", "", ""));
}

std::string replies_generator::privmsg_wildtoplevel(const string& mask)
{
	return(generate_msg(444, mask, "", "", ""));
}

std::string replies_generator::privmsg_nosuchnick(const string& user_nick)
{
	return(generate_msg(401, user_nick, "", "", ""));
}

std::string replies_generator::privmsg_toomanytargets(const string& target)
{
	return(generate_msg(407, target, "", "", ""));
}

std::string replies_generator::stats_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::time_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::topic_needmoreparams()
{
	return(generate_msg(461, "TOPIC", "", "", ""));
}

std::string replies_generator::topic_notonchannel(const string& channel_name)
{
	return(generate_msg(442, channel_name, "", "", ""));
}	

std::string replies_generator::topic_chanoprivsneeded(const string& channel_name)
{
	return(generate_msg(482, channel_name, "", "", ""));
}

std::string replies_generator::topic_nochanmodes(const string& channel_mode)
{
	return(generate_msg(477, channel_mode, "", "", ""));
}

std::string replies_generator::user_needmoreparams()
{
	return(generate_msg(461, "USER", "", "", ""));
}

std::string replies_generator::user_alreadyregistred(void)
{
	return(generate_msg(462, "", "", "", ""));
}

std::string replies_generator::userhost_needmoreparams()
{
	return(generate_msg(461, "USERHOST", "", "", ""));
}

std::string replies_generator::users_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::users_fileerror(const string& f_o, const string& file)
{
	return(generate_msg(424, f_o, file, "", ""));
}

std::string replies_generator::users_usersdisabled(void)
{
	return(generate_msg(446, "", "", "", ""));
}

std::string replies_generator::version_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::wallops_needmoreparams()
{
	return(generate_msg(461, "WALLOPS", "", "", ""));
}

std::string replies_generator::who_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::whois_nosuchserver(const string& server_name)
{
	return(generate_msg(402, server_name, "", "", ""));
}

std::string replies_generator::whois_nonicknamegiven(void)
{
	return(generate_msg(431, "", "", "", ""));
}

std::string replies_generator::whois_nosuchnick(const string& user_nick)
{
	return(generate_msg(401, user_nick, "", "", ""));
}

std::string replies_generator::whowas_nonicknamegiven(void)
{
	return(generate_msg(431, "", "", "", ""));
}

std::string replies_generator::whowas_wasnosuchnick(const string& user_nick)
{
	return(generate_msg(406, user_nick, "", "", ""));
}

//user_lisr is the list when load the reply
//reply is the msg to load mmsg_out to send in the future
void replies_generator::load_reply_to_users(std::queue<user> &user_list, std::string reply)
{
	while(!user_list.empty())
	{
		user_list.front().msg_out.add_msg(reply);
		user_list.pop();
	}
}


