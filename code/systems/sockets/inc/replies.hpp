/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:11:27 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/17 19:26:48 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REPLIES_HPP_
# define _REPLIES_HPP_

#include <string>
#include <sstream>
#include "ft_ircserv.hpp"
#include "replies_exceptions.hpp"
#include "rpl.hpp"

class replies
{
	private:
		int			head_len;
		std::string generate_send_code(const int &code);

    public:
		std::string	generate_msg(const int code, std::string arg1, std::string arg2, std::string arg3, std::string arg4);
		void		set_head_len(const int i);
        int         get_head_len();
		std::string	target_string;
		std::string	hostname;
};
#endif
