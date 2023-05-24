/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:42:55 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/24 00:52:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ORCHESTATOR_HPP_
# define _ORCHESTATOR_HPP_

#include <map>
#include <queue>
#include "orchestator_exceptions.hpp"
#include "com.hpp"
#include "user.hpp"
#include "../inc/internal_commands.hpp"
#include "../../database/db/Database.hpp"

class orchestator : public com
{
	private:
		std::string name;
		void										insert_new_user(const int fd);
		void										delete_user(const int fd);
		Database	&db;

	public:
		void										delete_users_from_list();
		std::queue<std::pair<int, std::string> >	kill_list;
		std::map<int, user>	users;

		orchestator(int port, Database &db);
        void	orchestation();
        void	recv_msgs(const int fd);
		void	send_msgs(const int fd);
		void	accept_new_connect();
        void	read_or_write_all_users();
		void	recv_msg_from_user(const int fd);
		void	send_msg_from_user(const int fd);
		void	check_status();
		void	clean_up();
};
#endif
