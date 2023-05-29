/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:53:33 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/11 19:54:59 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/time_control.hpp"
#include <iostream>

time_control::time_control(): kick(OK), s_ping(false)
{ 
//	start_time = std::chrono::high_resolution_clock::now();
	time_t now = time_control::get_time();
	this->t_last_msg = now; //time when last msg send
	this->t_set_pollout = LONG_MAX; //time to set to pollout
	this->t_ping = LONG_MAX; //time when send last ping
	this->set_s_ping(false);
	this->t_not_login = now;
}

time_t	time_control::get_t_ping() const
{ 
	return this->t_ping; 
}

void	time_control::set_t_ping(const time_t time) 
{ 
	this->t_ping = time; 
}

time_t	time_control::get_t_last_msg() 
{ 
	return this->t_last_msg;
}

//when received a msg form user get the time now to
//countdown to sen the ping
void	time_control::reset_t_last_msg()
{
	this->t_last_msg = time_control::get_time();	
}

time_t	time_control::get_t_not_login() 
{
	return this->t_not_login; 
}

void	time_control::set_t_not_login(const time_t time)
{
	this->t_not_login = time;	
}

void	time_control::reset_t_not_login() 
{ 
	this->t_not_login = LONG_MAX; 
}

void	time_control::reset_t_ping() 
{ 
	this->t_ping = LONG_MAX; 
	this->set_s_ping(false);
}

void	time_control::set_kick(const bool value) 
{ 
	this->kick = value; 
}

bool	time_control::get_kick() 
{ 
	return this->kick; 
}

time_t	time_control::get_time() 
{ 
	return std::time(NULL); 
}

void	time_control::get_time(time_t* var) 
{ 
	std::time(var); 
}

void	time_control::launch_t_ping()
{
	this->t_ping = time_control::get_time();
	this->set_s_ping(true);
}

void	time_control::launch_t_last_msg()
{
	this->t_last_msg = time_control::get_time();
}

void	time_control::reset_ping_time() 
{ 
	this->t_ping = LONG_MAX; 
}

//This function check all time values
//If one value exced the time parametres set kick variable ti KICK
//At the end of cycle all users set to KICK kick
//
//I completely agree with the above statement (whatever that is). Signed: 𝓙𝓪𝓿𝓰𝓸𝓷𝔃𝓪
void	time_control::check_if_kick_logged()
{
	time_t	now = time_control::get_time();	

	if((now - this->t_ping) > TIME_PING && this->s_ping == true)
	{
		this->kick = KICK;
	}
}

void	time_control::check_if_kick_not_logged()
{
	time_t	now = time_control::get_time();	

	if((now - this->t_not_login) > TIME_DONT_LOGIN)
		this->kick = KICK;
}

bool	time_control::launch_send_ping() const
{
	time_t	now = time_control::get_time();	
	bool	answ = false;

	if((now - this->t_last_msg) > TIME_LAST_MSG)
		answ = true;
	//TODO: ask tomartin
//	if((now - this->t_set_pollout) > TIME_LAST_MSG)
//		answ = true;
	return(answ);
}

void	time_control::set_s_ping(bool value)
{
	this->s_ping = value;
}

bool	time_control::get_s_ping() const
{
	return(this->s_ping);
}

//__________________DEBUG___________________//

void	time_control::print_times()
{
	std::cout << "TIME T_PING: " << this->t_ping << std::endl;
	std::cout << "TIME T_NOT_LOGIN: " << this->t_not_login << std::endl;
	std::cout << "TIME T_SET_POLLOUT: " << this->t_set_pollout << std::endl;
	std::cout << "TIME T_LAST_MSG: " << this->t_last_msg << std::endl;
	std::cout << "KICK FLAG: " << this->kick << std::endl;
	std::cout << "SEND PING: " << this->s_ping << std::endl;
}



