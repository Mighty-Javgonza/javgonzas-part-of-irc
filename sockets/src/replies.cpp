/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:51:30 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/17 20:00:02 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replies.hpp"

std::string	replies::generate_send_code(const int& code)
{
	std::string			true_code;
	std::stringstream	ss;

	true_code = ft_itoa(code);
	while(true_code.size() < 3)
		true_code.insert(0, 1, '0');
    return true_code;
}

//Generat a str with the numeric reply
//Set the value header variable you can use if the reply is more
//big than 512
std::string replies::generate_msg(const int code, std::string arg1, std::string arg2, std::string arg3, std::string arg4)
{
	this->set_head_len(0);
    std::string send_code(generate_send_code(code));
    //Temporal---------------------------------------//

	std::string	head(":" + hostname + " " + send_code + " " + target_string + " ");
	this->set_head_len(head.size() + 1);
	switch (code)
	{
		case 1:
			return head + RPL_WELCOME(arg1);
		case 2:
			return head + RPL_YOURHOST(arg1, arg2);
		case 3:
			return head + RPL_CREATED(arg1);
		case 4:
			return head + RPL_MYINFO(arg1, arg2, arg3, arg4);
		case 5:
			return head + RPL_BOUNCE(arg1, arg2);
		case 200:
			return head + RPL_TRACELINK(arg1, arg2);
		case 203:
			return head + RPL_TRACEUNKNOWN(arg1);
		case 204:
			return head + RPL_TRACEOPERATOR(arg1);
		case 205:
			return head + RPL_TRACEUSER(arg1);
		case 206:
			return head + RPL_TRACESERVER(arg1);
		case 211:
			return head + RPL_STATSLINKINFO(arg1);
		case 212:
			return head + RPL_STATSCOMMANDS(arg1, arg2, arg3, arg4);
		case 219:
			return head + RPL_ENDOFSTATS(arg1);
		case 221:
			return head + RPL_UMODEIS(arg1);
		case 242:
			return head + RPL_STATSUPTIME(arg1);
		case 251:
			return head + RPL_LUSERCLIENT(arg1, arg2, arg3);
		case 252:
			return head + RPL_LUSEROP(arg1);
		case 253:
			return head + RPL_LUSERUNKNOWN(arg1);
		case 254:
			return head + RPL_LUSERCHANNELS(arg1);
		case 255:
			return head + RPL_LUSERME(arg1, arg2);
		case 256:
			return head + RPL_ADMINME(arg1);
		case 257:
			return head + RPL_ADMINLOC1(arg1);
		case 258:
			return head + RPL_ADMINLOC2(arg1);
		case 259:
			return head + RPL_ADMINEMAIL(arg1);
		case 262:
			return head + RPL_TRACEEND(arg1, arg2);
		case 301:
			return head + RPL_AWAY(arg1, arg2);
		case 302:
			return head + RPL_USERHOST(arg1);
		case 303:
			return head + RPL_ISON(arg1);
		case 305:
			return head + RPL_UNAWAY();
		case 306:
			return head + RPL_NOWAWAY();
		case 311:
			return head + RPL_WHOISUSER(arg1, arg2, arg3, arg4);
		case 312:
			return head + RPL_WHOISSERVER(arg1, arg2, arg3);
		case 313:
			return head + RPL_WHOISOPERATOR(arg1);
		case 314:
			return head + RPL_WHOWASUSER(arg1, arg2, arg3, arg4);
		case 315:
			return head + RPL_ENDOFWHO(arg1);
		case 317:
			return head + RPL_WHOISIDLE(arg1, arg2, arg3);
		case 318:
			return head + RPL_ENDOFWHOIS(arg1);
		case 319:
			return head + RPL_WHOISCHANNELS(arg1, arg2);
		case 322:
			return head + RPL_LIST(arg1, arg2);
		case 323:
			return head + RPL_LISTEND();
		case 324:
			return head + RPL_CHANNELMODEIS(arg1, arg2, arg3);
		case 329:
			return head + RPL_CREATIONTIME(arg1, arg2);
		case 331:
			return head + RPL_NOTOPIC(arg1);
		case 332:
			return head + RPL_TOPIC(arg1, arg2);
		case 341:
			return head + RPL_INVITING(arg1, arg2);
		case 346:
			return head + RPL_INVITELIST(arg1, arg2);
		case 347:
			return head + RPL_ENDOFINVITELIST(arg1);
		case 348:
			return head + RPL_EXCEPTLIST(arg1, arg2);
		case 349:
			return head + RPL_ENDOFEXCEPTLIST(arg1);
		case 351:
			return head + RPL_VERSION(arg1, arg2, arg3, arg4);
		case 352:
			return head + RPL_WHOREPLY(arg1);
		case 353:
			return head + RPL_NAMREPLY(arg1, arg2);
		case 364:
			return head + RPL_LINKS(arg1, arg2, arg3, arg4);
		case 365:
			return head + RPL_ENDOFLINKS(arg1);
		case 366:
			return head + RPL_ENDOFNAMES(arg1);
		case 367:
			return head + RPL_BANLIST(arg1);
		case 368:
			return head + RPL_ENDOFBANLIST(arg1);
		case 369:
			return head + RPL_ENDOFWHOWAS(arg1);
		case 371:
			return head + RPL_INFO(arg1);
		case 372:
			return head + RPL_MOTD(arg1);
		case 374:
			return head + RPL_ENDOFINFO();
		case 375:
			return head + RPL_MOTDSTART(arg1);
		case 376:
			return head + RPL_ENDOFMOTD();
		case 381:
			return head + RPL_YOUREOPER();
		case 382:
			return head + RPL_REHASHING(arg1);
		case 391:
			return head + RPL_TIME(arg1, arg2);
		case 392:
			return head + RPL_USERIP(arg1, arg2);
		case 393:
			return head + RPL_USERS(arg1);
		case 394:	
			return head + RPL_ENDOFUSERS();
		case 401:
			return head + ERR_NOSUCHNICK(arg1);
		case 402:
			return head + ERR_NOSUCHSERVER(arg1);
		case 403:
			return head + ERR_NOSUCHCHANNEL(arg1);
		case 404:
			return head + ERR_CANNOTSENDTOCHAN(arg1);
		case 405:
			return head + ERR_TOOMANYCHANNELS(arg1);
		case 406:
			return head + ERR_WASNOSUCHNICK(arg1);
		case 407:
			return head + ERR_TOOMANYTARGETS(arg1);
		case 409:
			return head + ERR_NOORIGIN();
		case 411:
			return head + ERR_NORECIPIENT(arg1);
		case 412:
			return head + ERR_NOTEXTTOSEND();
		case 421:
			return head + ERR_UNKNOWNCOMMAND(arg1);
		case 422:
			return head + ERR_NOMOTD();
		case 423:
			return head + ERR_NOADMININFO(arg1);
		case 424:
			return head + ERR_FILEERROR(arg1, arg2);
		case 431:
			return head + ERR_NONICKNAMEGIVEN();
		case 432:
			return head + ERR_ERRONEUSNICKNAME(arg1);
		case 433:
			return head + ERR_NICKNAMEINUSE(arg1);
		case 436:
			return head + ERR_NICKCOLLISION(arg1, arg2, arg3);
		case 437:
			return head + ERR_UNAVAILRESOURCE(arg1);
		case 441:
			return head + ERR_USERNOTINCHANNEL(arg1, arg2);
		case 442:
			return head + ERR_NOTONCHANNEL(arg1);
		case 443:
			return head + ERR_USERONCHANNEL(arg1, arg2);
		case 451:
			return head + ERR_NOTREGISTERED();
		case 461:
			return head + ERR_NEEDMOREPARAMS(arg1);
		case 464:
			return head + ERR_PASSWDMISMATCH();
		case 462:
			return head + ERR_ALREADYREGISTRED();
		case 471:
			return head + ERR_CHANNELISFULL(arg1);
		case 472:
			return head + ERR_UNKNOWNMODE(arg1, arg2);
		case 473:
			return head + ERR_INVITEONLYCHAN(arg1);
		case 475:
			return head + ERR_BADCHANNELKEY(arg1);
		case 476:
			return head + ERR_BADCHANMASK(arg1);
		case 477:
			return head + ERR_NOCHANMODES(arg1);
		case 481:
			return head + ERR_NOPRIVILEGES();
		case 482:
			return head + ERR_CHANOPRIVSNEEDED(arg1);
		case 483:
			return head + ERR_CANTKILLSERVER();
		case 491:
			return head + ERR_NOOPERHOST();
		case 501:
			return head + ERR_UMODEUNKNOWNFLAG();
		case 502:
			return head + ERR_USERSDONTMATCH();
		case 503:
			return head + ERR_TOOMANYMATCHES();
		default:
			return std::string("");
	}
	throw replies_exceptions(1);
	return "";
}

void	replies::set_head_len(const int i)
{
	this->head_len = i;
}

int		replies::get_head_len()
{
	return this->head_len;
}
