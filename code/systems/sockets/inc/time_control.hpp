/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:42:49 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/11 19:46:16 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TIME_CONTROL_HPP_
#define _TIME_CONTROL_HPP_

#include <ctime>
#include <climits>
#include "ft_ircserv.hpp"
#include <chrono>

class time_control
{
	private:
		time_t		t_ping;
		time_t		t_not_login;
		time_t		t_set_pollout;
		time_t		t_last_msg;
		bool		kick;
		bool		s_ping; //sended ping
//		std::chrono::high_resolution_clock::time_point	start_time;
	
	public:
		time_control();
		time_t				get_t_ping() const;
		void				set_t_ping(const std::time_t time);
		void				launch_t_ping();
		void				launch_t_last_msg();
		void				reset_ping_time();
		time_t				get_t_last_msg();
		void				reset_t_last_msg();
		time_t				get_t_not_login();
		void				set_t_not_login(const time_t time);
		void				reset_t_not_login();
		void				reset_t_ping();
		void				set_kick(const bool value);
		bool				get_kick();
		static time_t		get_time();
		static void			get_time(time_t* var);
		void				check_if_kick_logged();
		void				check_if_kick_not_logged();
		bool				launch_send_ping() const;
		void				set_s_ping(bool value);
		bool				get_s_ping() const;
		void				print_times();
};

#endif

