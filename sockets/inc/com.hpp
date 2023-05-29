/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:22:56 by tomartin          #+#    #+#             */
/*   Updated: 2023/04/24 18:27:41 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COM_HPP_
# define _COM_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <vector>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <poll.h>
#include <netdb.h>
#include "com_exceptions.hpp"
#include "ft_ircserv.hpp"
#include "log.hpp"

/*
struct sock_storage: public sockaddr_storage
{
	int			fd;
	socklen_t	addr_len;
};
*/

class com
{
    private:
        const int					port;
		//log							my_log;
        struct sockaddr_in			data_socket;
        int							fd_socket;
		std::vector<pollfd>			poll_list;
		std::vector<sock_info>		sock_struct_vector;

		void		open_socket();
        void		set_data_socket(const int port);
    	void		insert_in_poll_list(const int fd);
    	void		delete_in_poll_list(const int fd);

    public:
    	com(const int);
		~com();	
    	void		socket_lisent();
    	int			accept_connection_in_socket();
        int			preparation_com();
    	void		disconnect_user(const int fd, std::string reason);
    	void		disconnect_user(const int fd);
    	int			get_port() const;
    	int			get_fd_socket() const;
		int			set_value_poll_list(const int fd, const short event);
		int			send_msg(const int fd, const std::string);
		std::string	recv_msg(const int fd);
		short		get_revent(const int fd) const;
		short		get_event(const int fd) const;
    	void		close_connection(const int fd);
    	int			get_port();
    	static void	close_port(const int port);
    	int			get_ip() const;
		std::string	get_server_host_name() const;
		std::string	get_host_name() const;

		void	print_all_pollfd();
	};
#endif
