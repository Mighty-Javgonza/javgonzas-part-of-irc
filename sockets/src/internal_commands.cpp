/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_commands.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:49 by tomartin          #+#    #+#             */
/*   Updated: 2023/04/03 16:39:11 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/internal_commands.hpp"

//This command will send when it necesary check the clinet's conexion
//for example when the client pass a lot of time without send a msg
//...
void	internal_ping(user& user, std::string host_name)
{
	user.msg_out.direct_push(std::string(":" + host_name + " PING" + "\x0d\x0a"));
	user.user_times.launch_t_ping();
	user.user_times.set_s_ping(true);
}

/*
//This command is the reply when the server received a ping msg
void	internal_pong(user& user)
{
	bool	parse = true;

	if(parse == true)
	{
		user.user_times.reset_t_ping();
}

void	time(user& user, std::string host_name)
{
	std::time_t	t = time_control::get_time();
	tm	*st = localtime(&t);
	std::stringstream	ms;

	ms << "TIME " << std::setfill('0') << std::setw(2) << ft_itoa(st->tm_hour) << ":" 
		<< std::setw(2) << ft_itoa(st->tm_min) << ":" << std::setw(2) << ft_itoa(st->tm_sec) <<"\n" << "DATE " 
		<< ft_itoa(st->tm_year + 1900) << "/" << std::setw(2) << ft_itoa(st->tm_mon + 1) << "/" 
		<< std::setw(2) << ft_itoa(st->tm_mday) << "\x0d\x0a"; 
	user.msg_out.direct_push(std::string(":" + host_name + " " + ms.str()));
}
*/
