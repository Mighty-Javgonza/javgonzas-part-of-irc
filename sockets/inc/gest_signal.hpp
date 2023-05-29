/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_signal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:31:28 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/22 19:14:49 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GEST_SIGMALHPP_
# define _GEST_SIGMALHPP_

#include <signal.h>
#include "com.hpp"

class gest_signal
{
	private:
	com&	my_com;

	public:
	gest_signal(com& _com);
	void handle();
	static void	f_sigint(int sig);


};
#endif


