/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp_exceptions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:41:20 by tomartin          #+#    #+#             */
/*   Updated: 2022/11/06 16:54:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_EXCEPTION_HPP_
# define _REPLIES_EXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <cstdlib>

class replies_exceptions : public std::exception
{
	private:
		void    fail_generate_msg();

	public:
		replies_exceptions(const int num);
		const char*	what() const throw();
};
#endif
