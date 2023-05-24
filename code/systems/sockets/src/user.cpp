/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:17:58 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/05 16:26:46 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/user.hpp"

user::user(int fd, char type, std::string host_name) : _fd(fd), type(type), host_name(host_name)
{
	std::cout << "HOSTNAME-> " << get_host_name() << std::endl;
	std::cout << "FD-> " << get_fd() << std::endl;
	//set times
}

void	user::set_nick(const std::string name)
{
	this->nick = name;
}
	
void	user::set_type(const char type)
{
	this->type = type;
}
/*
short   user::send_or_recive() const
{
	if(this->type == EXPULSE)
		return POLLRDBAND;
    if(this->msg_out.check_if_empty())
        return POLLIN;
    return POLLOUT;
}
*/
std::string user::get_host_name() const
{
	return this->host_name;
}

int	user::get_fd() const
{
	return this->_fd;
}
