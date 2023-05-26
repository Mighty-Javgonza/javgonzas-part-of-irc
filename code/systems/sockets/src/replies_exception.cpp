/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp_exception.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:43:53 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/06 16:55:29 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replies_exceptions.hpp"

replies_exceptions::server_exceptions(const int num)
{
	switch(num)
	{
		case 1: //when open socket fail
			this->fail_generate_msg();
			break;
	}
}

const	char* replies_exceptions::what() const throw()
{
	return "Custom exception in replies_exception";
}

void    replies_exception::fail_generate_msg();
{
    std::cerr << "Not found code in rpl list" << std::endl;
   	std::cerr << this->what() << std::endl;
}
