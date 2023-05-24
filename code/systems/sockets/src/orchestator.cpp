/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:28 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/24 00:52:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/orchestator.hpp"
#include <iostream>

#include "../../database/db/Database.hpp"
#include "../../command_executor/code/source/ServerInfo/ServerInfo.hpp"

orchestator::orchestator(int port, Database &db) : com(port), db(db)
{
	int	fd = get_fd_socket();
	socket_lisent();
	//users.insert(std::pair<int, user>(fd, user(fd, SOCKET)));
	set_value_poll_list(fd, POLLIN);
	this->name = get_server_host_name();
}

void	orchestator::insert_new_user(const int fd)
{
	(void) fd;
//	std::string	host_name = get_host_name();
//	users.insert(std::make_pair(fd, user(fd, UNKNOW, host_name)));
}

void	orchestator::delete_user(const int fd)
{
	this->users.erase(fd);
	disconnect_user(fd);	
}

//Accept new connection if the server is full
//kick out the new connexion
void	orchestator::accept_new_connect()
{
	int			fd;

	fd = accept_connection_in_socket();
	if(fd != -1)
	{
//		insert_new_user(fd);
		std::cout << "CONEXION IN FD " << fd << std::endl;
//		send_msg(fd, "HOLA\n");

		///IN THE BEGINNING WERE THE TROUBLES
	//
		//TODO: End the troubles
		ClientId id("", get_host_name(), fd);
		db.UnregisteredClients().Insert(Unregistered(id, true));
	//
		///END OF THE BEGGINING

	}
	if(users.size() > MAX_CONNECTIONS)
	{
//		this->users.find(fd)->second.set_type(EXPULSE);
		disconnect_user(fd, "PIRATE SERVER LLENO");
		this->delete_user(fd);
		return;
	}
}

//This function scroll through the entire list of users
//If the user have POLLIN event, it read de msg
//If the user have msg in msg_q_out, it send msg
//It's the heard of send-recv orchestator
void    orchestator::orchestation()
{
//	std::map<int, user>::iterator	usr_it = users.begin();
	//std::vector<int>				delete_list;

//	while(usr_it != users.end())
  //  {
//		if (get_revent(usr_it->first & (POLLHUP)))
//		{
//			std::cout << "POLLHUB RECV\n";
//			this->kill_list.push(std::make_pair(usr_it->first, std::string("POLLHUP")));
			//Desconectar
//		}
//		else
//		{
			//TO READ
        	//this->recv_msgs(usr_it->first);
        	//TO SEND
        	//this->send_msgs(usr_it->first);
//		}
   //     ++usr_it;
    //}
    //delete_users_from_list(delete_list);
}


//This function get the list that is generated in the orchestaton function 
//and contains all sockets that have received a POLLHUP(forcing disconnection) signal
//iterates through the entire list, deleting and removing the sockets in the list
void	orchestator::delete_users_from_list()
{
	while(!(this->kill_list.empty()))
	{
std::cout << "DELETING USER" << std::endl;
		std::pair<int, std::string> 	user_kill = this->kill_list.front();
		disconnect_user(user_kill.first);
		users.erase(user_kill.first);
		close_connection(user_kill.first);
		// To debug
		std::cout << "Desconectado FD: " << user_kill.second << " FD" << user_kill.first<< std::endl;
		this->kill_list.pop();
	}
}

//This function send msgs from msg_out queue in user
//Only send if msg_out queue have any msg
//If msg can't send all chars, it resize msg and 
//erase the msg part will be send suscessfull
//If whill be send all chars in msg and the socket is
//set POLLOUT it's set POLLIN because it's restore the connection
void	orchestator::send_msgs(const int fd)
{
    int                             send_leng;
	ClientData	*client = db.get_client_data_from_fd(fd);

	if(client->msg_out.msg_q_size() == 0)
		return;
	if(!(get_event(fd) & POLLOUT) || (get_revent(fd) & POLLOUT)) 
   {
		std::string	message = client->msg_out.extract_msg();
		message += "\r\n";
		send_leng = send_msg(fd, message);
		if(send_leng < client->msg_out.msg_front_len())
			client->msg_out.erase_front_msg(send_leng);
		else
		    client->msg_out.pop_msg();
			if(get_revent(fd) & POLLOUT)
				set_value_poll_list(fd, POLLIN);
    }
}

//This function read and load msg in one user
void    orchestator::recv_msgs(const int fd)
{
    if((get_revent(fd) & POLLIN))
	{
		ClientData *client = db.get_client_data_from_fd(fd);

		client->msg_in.add_msg(recv_msg(fd));
	}
}

/*
//This funciton sen a msg from user
//If the msg dont sent complety put the fd in POLLOUT
void	orchestator::send_msg_from_user(const int fd)
{
	std::string						msg;
    std::map<int, user>::iterator   usr = users.find(fd);
    int								b_send;

	msg = usr->second.msg_out.extract_msg();
	b_send = send_msg(fd, msg);
	if(b_send < static_cast<int>(msg.size()))
		set_value_poll_list(fd, POLLOUT);
}
*/

void	orchestator::recv_msg_from_user(const int fd)
{
	std::string	msg;

	msg = recv_msg(fd);
	db.get_unregistered_from_fd(fd)->msg_in.add_msg(msg);
}

void	orchestator::check_status()
{
	//this function check all statatus of users, msg, etc
	//if one exced the values in ft_ircserv.hpp
	//whill be kicked
	
	//1º check times values user.time_control.check_if_kick();
	//2º check msg lengs user.recv_msg_q.check_status_queue();
	//...
//	if(this->users.empty() != true)
//	{
//		std::map<int, user>::iterator	it = this->users.begin();
//		for(;it != this->users.end(); it++)
//		{
//			it->second.user_times.check_if_kick();
//			if(it->second.user_times.launch_send_ping() &&
//			   it->second.user_times.get_s_ping() == false)
//			{
//				internal_ping(it->second, this->name);
//			}
//		}
//	}
}

void	orchestator::clean_up()
{
	std::map<int, user>::iterator	it = this->users.begin();
	for(;it != this->users.end(); it++)
	{
		std::cout << it->second.user_times.get_kick() << std::endl;
		if(it->second.user_times.get_kick() == KICK)
			this->kill_list.push(std::make_pair(it->first, std::string("EN KICK")));
	}
	this->delete_users_from_list();
}
