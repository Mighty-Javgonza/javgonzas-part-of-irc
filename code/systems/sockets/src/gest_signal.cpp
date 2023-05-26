/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_signal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:55:04 by tomartin          #+#    #+#             */
/*   Updated: 2023/01/22 19:32:10 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gest_signal.hpp"
#include <iostream>

gest_signal::gest_signal(com& _com) : my_com(_com)
{
	(void) my_com;
}

void gest_signal::handle()
{
	signal(SIGINT, f_sigint); 
}

void gest_signal::f_sigint(int sig)
{
	(void) sig;
}

