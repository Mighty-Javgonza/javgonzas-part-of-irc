/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_resp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:04:23 by tomartin          #+#    #+#             */
/*   Updated: 2022/12/24 15:05:11 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user.hpp"
#include "replies_generator.hpp"
#include "aux_server.hpp"

int main(void)
{
	user	load(99, UNKNOW); //when load replies
	user	a(100, UNKNOW); //example user

	replies_generator	generator;
	aux_server			serv; //example server
	aux_channel			chan; //example chanel
	std::string			demo(500, 'A');
	demo[200] = ' ';

	load.msg_out.add_msg(generator.admin_ok(serv, a));
	load.msg_out.add_msg(generator.away_rpy(a));
	load.msg_out.add_msg(generator.away_unaway());
	load.msg_out.add_msg(generator.away_nowaway());
	load.msg_out.add_msg(generator.info_rpy(serv));
	load.msg_out.add_msg(generator.invite_ok(serv, a));
	load.msg_out.add_msg(generator.invite_away(a));
	load.msg_out.add_msg(generator.ison_ok("ISON LIST"));
	load.msg_out.add_msg(generator.join_ok(serv));
	load.msg_out.add_msg(generator.list_ok(serv));
	load.msg_out.add_msg(generator.mode_us_ok(a));
	load.msg_out.add_msg(generator.mode_ch_ok(chan));
	load.msg_out.add_msg(generator.mode_banlist(chan));
	load.msg_out.add_msg(generator.mode_exceptlist(chan));
	load.msg_out.add_msg(generator.mode_invitelist(chan));
	load.msg_out.add_msg(generator.mode_uniqopis(chan, a));
	load.msg_out.add_msg(generator.motd_ok(serv));
	load.msg_out.add_msg(generator.names_ok(chan));
	load.msg_out.add_msg(generator.oper_ok(serv));
	load.msg_out.add_msg(generator.stats_l(serv));
	load.msg_out.add_msg(generator.stats_m(serv));
	load.msg_out.add_msg(generator.stats_o(serv));
	load.msg_out.add_msg(generator.stats_u(serv));
	load.msg_out.add_msg(generator.time(serv));
	load.msg_out.add_msg(generator.topic_ok(chan));
	load.msg_out.add_msg(generator.topic_no(chan));
	load.msg_out.add_msg(generator.user_ok(serv));
	load.msg_out.add_msg(generator.user_empty());
	load.msg_out.add_msg(generator.version_ok(serv));
	load.msg_out.add_msg(generator.version_ok(serv));
	load.msg_out.add_msg(generator.admin_fail(serv));
	load.msg_out.add_msg(generator.die_fail());
	load.msg_out.add_msg(generator.info_fail(serv));
	load.msg_out.add_msg(generator.invite_moreparams("COMANDO"));
	load.msg_out.add_msg(generator.invite_nosuchnick(chan));
	load.msg_out.add_msg(generator.invite_notonchannel(chan));
	load.msg_out.add_msg(generator.invite_useronchannel(a, chan));
	load.msg_out.add_msg(generator.invite_chanoprivsneeded(chan));
	load.msg_out.add_msg(generator.ison_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.join_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.join_bannedfromchan(chan));
	load.msg_out.add_msg(generator.join_inviteonlychan(chan));
	load.msg_out.add_msg(generator.join_badchannelkey(chan));
	load.msg_out.add_msg(generator.join_channelisfull(chan));
	load.msg_out.add_msg(generator.join_badchanmask(chan));
	load.msg_out.add_msg(generator.join_nosuchchannel(chan));
	load.msg_out.add_msg(generator.join_toomanychannels(chan));
	load.msg_out.add_msg(generator.kick_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.kick_nosuchchannel(chan));
	load.msg_out.add_msg(generator.kick_badchanmask(chan));
	load.msg_out.add_msg(generator.kick_chanoprivsneeded(chan));
	load.msg_out.add_msg(generator.kick_notonchannel(chan));
	load.msg_out.add_msg(generator.kill_noprivileges());
	load.msg_out.add_msg(generator.kill_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.kill_nosuchnick(a));
	load.msg_out.add_msg(generator.list_nosuchserver(serv));
	load.msg_out.add_msg(generator.mode_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.mode_chanoprovsneeded(chan));
	load.msg_out.add_msg(generator.mode_nosuchnick(a));
	load.msg_out.add_msg(generator.mode_notonchannel(chan));
	load.msg_out.add_msg(generator.mode_keyset(chan));
	load.msg_out.add_msg(generator.mode_unknownmode("c", chan));
	load.msg_out.add_msg(generator.mode_nosuchchannel(chan));
	load.msg_out.add_msg(generator.mode_usersdontmatch());
	load.msg_out.add_msg(generator.mode_umodeunknownflag());
	load.msg_out.add_msg(generator.modt_nomodtd());
	load.msg_out.add_msg(generator.nick_nonicknamegiven());
	load.msg_out.add_msg(generator.nick_erroneusnickname(a));
	load.msg_out.add_msg(generator.nick_nicknameinuse(a));
	load.msg_out.add_msg(generator.oper_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.oper_nooperhost());
	load.msg_out.add_msg(generator.oper_passwdmismatch());
	load.msg_out.add_msg(generator.part_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.part_nosuchchannel(chan));
	load.msg_out.add_msg(generator.part_notonchannel(chan));
	load.msg_out.add_msg(generator.pass_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.pass_alreadyregistred());
	load.msg_out.add_msg(generator.ping_noorigin());
	load.msg_out.add_msg(generator.ping_nosuchserver(serv));
	load.msg_out.add_msg(generator.pong_noorigin());
	load.msg_out.add_msg(generator.pong_nosuchserver(serv));
	load.msg_out.add_msg(generator.privmsg_norecipient("COMMAND"));
	load.msg_out.add_msg(generator.privmsg_notexttosend());
	load.msg_out.add_msg(generator.privmsg_cannotsendtochan(chan));
	load.msg_out.add_msg(generator.privmsg_notoplevel("MASK"));
	load.msg_out.add_msg(generator.privmsg_wildtoplevel("MASK"));
	load.msg_out.add_msg(generator.privmsg_nosuchnick(a));
	load.msg_out.add_msg(generator.stats_nosuchserver(serv));
	load.msg_out.add_msg(generator.time_nosuchserver(serv));
	load.msg_out.add_msg(generator.topic_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.topic_notonchannel(chan));
	load.msg_out.add_msg(generator.topic_chanoprivsneeded(chan));
	load.msg_out.add_msg(generator.user_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.user_alreadyregistred());
	load.msg_out.add_msg(generator.userhost_needmoreparams("COMMAND"));
	load.msg_out.add_msg(generator.users_nosuchserver(serv));
	load.msg_out.add_msg(generator.users_fileerror("?", "FILE"));
	load.msg_out.add_msg(generator.users_usersdisabled());
	load.msg_out.add_msg(generator.version_nosuchserver(serv));
	load.msg_out.add_msg(generator.wallops_needmoreparams("COMMAND"));
	load.msg_out.add_msg(load.msg_out.fragmentation_msg_send(generator.wallops_needmoreparams(demo), generator.get_head_len()));
	load.msg_out.add_msg(generator.who_nosuchserver(serv));
	load.msg_out.add_msg(generator.whois_nosuchserver(serv));
	load.msg_out.add_msg(generator.whois_nonicknamegiven());
	load.msg_out.add_msg(generator.whowas_nonicknamegiven());
	load.msg_out.add_msg(generator.whowas_wasnosuchnick(a));

	load.msg_out.print_all_msg();
}
