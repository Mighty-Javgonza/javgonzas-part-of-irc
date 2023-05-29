/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp_exception.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:43:53 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/26 16:49:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replies_exceptions.hpp"

replies_exceptions::replies_exceptions(const int num)
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

void    replies_exceptions::fail_generate_msg()
{
    std::cerr << "Not found code in rpl list" << std::endl;
   	std::cerr << this->what() << std::endl;
}
