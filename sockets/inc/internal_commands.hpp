/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_commands.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:05:01 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:03:14 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERNAL_COMMANDS_HPP_
# define _INTERNAL_COMMANDS_HPP_

#include <string>
#include <iomanip>
#include <sstream>
#include "user.hpp"
#include "replies.hpp"

void	internal_ping(user& user, std::string host_name);
//void	internal_pong(user& user);
//void	time(user& user, std::string host_name);

#endif
