/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_exceptions.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:09:37 by tomartin          #+#    #+#             */
/*   Updated: 2023/02/05 20:31:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COM_EXCEPTION_HPP_
# define _COM_EXCEPTION_HPP_

#include <exception>
#include <iostream>
#include <cstdlib>

class com_exceptions : public std::exception
{
	private:
		std::string	type;
		std::string	msg;
		int			err_code;
		
	public:
		com_exceptions(const std::string& msg, int num);
		virtual ~com_exceptions() throw() {}
		void	print_error();
		int		get_err_code() const;
};
#endif
