/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_channel.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:41 by tomartin          #+#    #+#             */
/*   Updated: 2023/03/11 17:43:08 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUX_CHANNEL_HPP_
# define _AUX_CHANNEL_HPP_

#include <string>

struct aux_channel
{
	std::string get_name() const {return("CHANEL NAME PIMIENTO");}
	std::string get_info() const {return("CHANEL INFO HELLO");}
	std::string get_topic() const {return("CHANEL TOPIC");}
	std::string get_mode() const {return("+CEFJSTdfjnrtuxy");}
	std::string get_mod_params() const {return("*4:1800:10:10 3:...");}
	std::string get_ban_list() const {return("PEPE BANNED BY PEDRO ON ...");}
	std::string get_excep_list() const {return("exception m:auiiaa36!*@*...");}
	std::string get_invite_list() const {return("yo que coño se...");}
	std::string get_names_list() const {return("NAME LIST CMD NAMES");}
	std::string get_nickname_q() const {return("ONE NIKNAME");}
	std::string get_channel_topic() const {return("ONE TOPIC");}
	std::string get_params() const {return("NPI");}
};

#endif
