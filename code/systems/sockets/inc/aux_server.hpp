/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_server.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:41 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/09 21:07:42 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUX_SERVER_HPP_
# define _AUX_SERVER_HPP_

#include <string>

struct aux_server
{
	std::string get_name() const {return("SERVER NAME PATATA");}
	std::string get_info() const {return("SERVER INFO HOLA");}
	std::string get_chanel_name() const {return("#CHANEL");}
	std::string get_chanel_topic() const {return("CHANEL TOPIC");}
	std::string get_motd() const {return("MSG OF THE DAY");}
	std::string get_stats_letter() const {return("l");}
	std::string get_stats_l() const {return("RETURN STATS L CMD, A LOT OF INFO");}
	std::string get_stats_m() const {return("RETURN STATS M CMD, A LOT OF INFO");}
	std::string get_stats_o() const {return("RETURN STATS O CMD, A LOT OF INFO");}
	std::string get_stats_u() const {return("Server up 6 days, 12:20:56");}
	std::string get_time() const {return("Sun Nov 20 2022 19:12:35");}
	std::string get_userhost_rpy() const {return("tomartin=+tomartin@195.44...");}
	std::string users_rpy() const {return("tomartin ttys000  Nov 21 18:39");}
	std::string get_version() const {return("V 1.0");}
	std::string get_debug_lvl() const {return("???");}
	std::string get_comment() const {return("Hola este es el server guay");}
	std::string get_channel_list() const {return("Channel1, channel2");}

};
#endif
