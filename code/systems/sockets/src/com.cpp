/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:35:15 by tomartin          #+#    #+#             */
/*   Updated: 2023/05/10 18:12:41 by javgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/com.hpp"
#include <iostream>

com::com(const int port) : port(port)
{
	//Prereserve poll_list 
	//+2 is for socket and conexion over the limit
    this->poll_list.reserve(MAX_CONNECTIONS + 2);
	this->set_data_socket(port);
	this->open_socket();
}

com::~com()
{
	close(this->fd_socket);
}

void	com::set_data_socket(const int port)
{
    this->data_socket.sin_family = AF_INET;
    this->data_socket.sin_addr.s_addr = INADDR_ANY;
    this->data_socket.sin_port = htons(port);
    //this->data_socket_len = sizeof(data_socket);
    //this->port = port;
}

//Open socket. If can't do it launch a exception
//then set values in socket with setsockopt()
//Add to vector poll_list the socket
void	com::open_socket() 
{
    int					enable = 1;
    int					fcntl_control;
    int					bind_control;

    this->fd_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(this->fd_socket == -1)
    	throw com_exceptions("Error Open Socket", 1);

    setsockopt(this->fd_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable));    
	
	bind_control = bind(this->fd_socket, (const sockaddr*)&(this->data_socket), sizeof(data_socket));
	if (bind_control == -1)
		throw com_exceptions("Error bind", 3);

	fcntl_control = fcntl(this->fd_socket, F_SETFL, O_NONBLOCK);
	if (fcntl_control == -1)
		throw com_exceptions("Error fcntl", 2);
	poll_list.push_back((pollfd){this->fd_socket, POLLIN, 0});
}

//Put a socket in lisening
void com::socket_lisent()
{
	int	listen_control;

	listen_control = listen(this->fd_socket, MAX_CONNECTIONS);
	if (listen_control == -1)
		throw com_exceptions("Error listen", 4);
}

//Accept new connection in socket an put on nonblock
//Add to poll_list vector
//Return the new connect fd
int com::accept_connection_in_socket()
{
    sock_info	client;
    int new_fd = -1;

    client.ss_family = AF_INET;
    client.addr_len = sizeof(sockaddr_in);
    if (this->poll_list[0].revents & POLLIN)
    {
            new_fd = accept(this->fd_socket, (struct sockaddr *)&(client),
                            &client.addr_len);
            if(new_fd == -1)
				throw com_exceptions("Error accept", 6);
            client.fd = new_fd;
            this->sock_struct_vector.push_back(client);
            fcntl(new_fd, F_SETFL, O_NONBLOCK);
            this->poll_list.push_back((pollfd){new_fd, POLLIN, 0});
    }
    return new_fd;
}


//This function set all pollfd.revent to 0 and execut poll()
//If poll fail throw a com_exception
int    com::preparation_com()
{
    int answ;

    answ = poll(&this->poll_list[0], this->poll_list.size(), 100);
    if(answ == -1)
    	throw com_exceptions("Error Poll list", 5);
    return answ;
}

//Rutine to disconnect one user. Close connection and 
//remove form poll_list
//Send a message with the reason for the disconnection
void	com::disconnect_user(const int fd, std::string reason)
{
	this->set_value_poll_list(fd, POLLRDBAND);
	this->send_msg(fd, reason);
	this->delete_in_poll_list(fd);
	this->close_connection(fd);
}

//Rutine to disconnect one user. Close connection and 
//remove form poll_list
void	com::disconnect_user(const int fd)
{
	this->delete_in_poll_list(fd);
	this->close_connection(fd);
}
//Close one connection
//Need the fd to close
void	com::close_connection(const int fd)
{
	close(fd);
}

//Return port value
int	com::get_port() const
{
	return this->port;
}

//Return fd socket
int	com::get_fd_socket() const
{
	return this->fd_socket;
}

//Insert element in poll_list
//Remember the pollfd from socket is inside the poll_list
void	com::insert_in_poll_list(const int fd)
{
	this->poll_list.push_back((pollfd){fd, 0, 0});
}

void	com::delete_in_poll_list(const int fd)
{
    std::vector<pollfd>::iterator it = this->poll_list.begin();
    
    while(it != this->poll_list.end())
	{
		if(it->fd == fd)
		{
			this->poll_list.erase(it);
			return;
		}
		it++;
	}
}

//Set one value in the poll_list
//Find the fd if not foun retunr -1 else return 1
int	com::set_value_poll_list(const int fd, const short event)
{
    std::vector<pollfd>::iterator it = this->poll_list.begin();

    while(it != this->poll_list.end())
    {
    	if(it->fd == fd)
		{
    		it->events = event;
    		return 1;
		}
		it++;
	}
	return -1;
}

//To send a msg
//If can't send all of chars change the socket to POLLOUT 
//Oterwise set to POLLIN
int	com::send_msg(const int fd, const std::string msg)
{
    int   send_leng;

	send_leng = send(fd, (char*)&(msg[0]), msg.size(), MSG_DONTWAIT);
    if(send_leng < static_cast<int>(msg.size()))
	{
    	this->set_value_poll_list(fd, POLLOUT);
        return send_leng;
	}
	else
		this->set_value_poll_list(fd, POLLIN);
    return send_leng;
}

//To read a msg
std::string com::recv_msg(const int fd)
{
    char    buff[513];
    ssize_t aux = 0;

    aux = recv(fd, buff, 512, MSG_DONTWAIT);
	if (aux == -1)
		return ("");
//	if(!aux)
//		this->disconnect_user(fd, "COM ERROR");
    buff[aux] = '\0';

    if(aux > 0)
        return std::string(buff);
    return std::string("");
}

short	com::get_revent(const int fd) const
{
    std::vector<pollfd>::const_iterator it = this->poll_list.begin();

    while(it != this->poll_list.end())
    {
    	if(it->fd == fd)
    		return it->revents;
    	it++;
	}
	return 0;
}

short    com::get_event(const int fd) const
{
    std::vector<pollfd>::const_iterator it = this->poll_list.begin();

    while(it != this->poll_list.end())
    {
    	if(it->fd == fd)
    		return it->events;
    	it++;
	}
	return -1;
}

//Return port value
int	com::get_port()
{
	return this->port;
}

void	com::close_port(const int port)
{
	close(port);
}

int		com::get_ip() const
{
	sock_info			tmp_sock = *(sock_struct_vector.end() - 1);
	struct sockaddr_in	client_addr;
	int					get_ip;	

    socklen_t addr_len = sizeof(client_addr);
    get_ip = getsockname(tmp_sock.fd, (struct sockaddr *)&client_addr, &addr_len);
    if (get_ip == -1)
		throw com_exceptions("Error getsockname", 7);
	return get_ip;
}

std::string	com::get_host_name() const
{
	sock_info	tmp_sock = *(sock_struct_vector.end() - 1);
    struct		sockaddr_in client_addr;
    socklen_t	addr_len = sizeof(client_addr);
    char		host_buffer[NI_MAXHOST];
    int			getsockname_result = getsockname(tmp_sock.fd, (struct sockaddr *)&client_addr, &addr_len);

    if (getsockname_result == -1)
        throw com_exceptions("Error getsockname", 7);
    int getnameinfo_result = getnameinfo((struct sockaddr *)&client_addr, sizeof(client_addr),
                                         host_buffer, sizeof(host_buffer),
                                         NULL, 0, 0);
    if (getnameinfo_result != 0)
        throw com_exceptions("Error getnameinfo", 8);

    return std::string(host_buffer);
}

std::string	com::get_server_host_name() const
{
	char host_buffer[NI_MAXHOST];
	gethostname(host_buffer, NI_MAXHOST);
	std::string	host_name(host_buffer);

	return(host_name);
}

/*
std::string	com::get_host_name() const
{
    char	host[NI_MAXHOST];
    int		tmp;
	sock_info	tmp_sock = *(sock_struct_vector.end() - 1);

    tmp = getnameinfo((struct sockaddr *)&(tmp_sock), sizeof(struct sockaddr_in), host, sizeof(host), NULL, 0, NI_NAMEREQD);
    if(tmp != 0)
	{
		tmp = getnameinfo((struct sockaddr *)&(tmp_sock), sizeof(struct sockaddr_in), host, sizeof(host), NULL, 0, NI_NUMERICHOST);
	}
	return std::string(host);
}
*/
//-------------TO DEBUG--------------------//
//Print all pollfd list with values
void	com::print_all_pollfd()
{
	std::vector<pollfd>::iterator it = this->poll_list.begin();

	while(it != this->poll_list.end())
	{
		std::cout << "FD-> " << it->fd << std::endl;
		std::cout << "EVENT-> " << it->events << std::endl;
		std::cout << "REVENT-> " << it->revents << std::endl;
        std::cout << "----------------------------------------" << std::endl;
		it++;
	}
}

