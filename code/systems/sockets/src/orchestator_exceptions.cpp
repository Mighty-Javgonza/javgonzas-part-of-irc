/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestator_exceptions.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:46:38 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/18 18:46:41 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "orchestator_exceptions.hpp"

orchestator_exceptions::orchestator_exceptions(const int num)
{
	switch(num)
	{
		case 1: //when open socket fail
			this->fail_poll_sincr();
			break;
	}
}

const	char* orchestator_exceptions::what() const throw()
{
	return "Custom exception in orchestator_exception";
}

void    orchestator_exceptions::fail_poll_sincr()
{
    std::cerr << "Error when set pollfd struct" << std::endl;
    std::cerr << "Maybe not found fd in vector pollfd" << std::endl;
    std::cerr << "At sometime the pollfd vector has not been update" << std::endl;
   	std::cerr << this->what() << std::endl;
}
