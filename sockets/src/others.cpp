/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:26:54 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/09 16:22:58 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ircserv.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iostream>
#include <cctype>
#include <cstdlib>

bool	check_first_arg_digit(std::vector<std::string>& args)
{
	std::string	std_arg(*(args.begin() + 1));
	for(int i = 0 ; std_arg[i] ; i++)
		if(!std::isdigit(std_arg[i]))
		{
			std::cerr << "CAN NOT CONECT WITH OTHER SERVER O SERVER ADDRES INCORRECT" << std::endl;
			args.clear();
			exit(1);
		}
	return(true);
}

int		get_arg_port(std::vector<std::string>& args)
{
	int port = std::atoi(args[1].c_str());
	if(port < 1 || port > 65535)
	{
		std::cerr << "INCORRECT PORT" << std::endl;
		args.clear();
		exit(1);
	}
	return(port);
}

//Get values to init ft_ircserv
//Parse the params
//Make a pair to irc_server port and passw
std::pair<int, std::string>	parse_arg(int argc, char **argv)
{
	std::vector<std::string>	args;
	std::pair<int, std::string>	setings(4242,"");

	for(int i = 0; i < argc; i++)
		args.push_back(std::string(argv[i]));
	if(argc == 1)
	{
		std::cout << "ft_ircserv start in Port:4242 Pass:OFF" << std::endl;
		args.clear();
		return(setings);
	}
	if(argc == 2)
	{
		check_first_arg_digit(args);
		setings.first = get_arg_port(args);	
		std::cout << "ft_ircserv start in Port:" << setings.first; 
		std::cout << " Pass:OFF" << std::endl;
	}
	if(argc == 3)
	{
		check_first_arg_digit(args);
		setings.first = get_arg_port(args);	
		setings.second = args[2];
		std::cout << "ft_ircserv start in Port:" << setings.first; 
		if(setings.second == "")
			std::cout << " Pass:OFF" << std::endl;
		else
			std::cout << " Pass:" << setings.second << std::endl;
	}
	if(argc == 4)
	{
		std::cerr << "CAN NOT CONECT WITH OTHER SERVER O SERVER ADDRES INCORRECT" << std::endl;
		args.clear();
		exit(1);
	}
	if(argc > 4)
	{
		std::cerr << "ARGUMENTS ERROR!!!" << std::endl; 
		args.clear();
		exit(1);
	}
	args.clear();
	return(setings);
}
