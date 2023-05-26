
#include "../sockets/inc/com.hpp"
#include "../database/db/Database.hpp"
#include "../command_executor/code/source/all_headers.hpp"
#include "../sockets/inc/orchestator.hpp"
#include "../input_stream_orquestator/CommandActionAssociator.hpp"
#include "../sockets/inc/ft_ircserv.hpp"
#include "../lexer/code/source/all_headers.hpp"
#include "main_loop.hpp"

void	server_shutdown(Database *database, orchestator *orchest, ServerInfo *server_info)
{
std::cout << "\n\n!!!SERVER IS SHUTTING DOWN!!!" << std::endl;
	std::vector<ClientId> *all_clients = database->get_all_users();
	for (std::vector<ClientId>::iterator it = all_clients->begin(); it != all_clients->end(); it++)
	{
		Client	*client = database->get_user_from_fd(it->Fd());
		std::cout << "Sending goodbye messages to user: " << client->Nick() << std::endl;
		while (client->msg_in.msg_q_size() > 0)
			client->msg_in.pop_msg();
		while (client->msg_out.msg_q_size() > 0)
			client->msg_out.pop_msg();
		client->msg_in.add_msg("QUIT :Server is shutting down\r\n");
	}
	delete all_clients;

	std::vector<ClientId> *all_unclients = database->UnregisteredClients().Vector();
	for (std::vector<ClientId>::iterator it = all_unclients->begin(); it != all_unclients->end(); it++)
	{
		Unregistered *client = database->get_unregistered_from_fd(it->Fd());
		while (client->msg_in.msg_q_size() > 0)
			client->msg_in.pop_msg();
		while (client->msg_out.msg_q_size() > 0)
			client->msg_out.pop_msg();
		*client << ":" + server_info->get_preffix_string() + " ERROR :Server is shutting down\r\n";
	}

	process_one_message_from_each_queue(*database, *orchest, *server_info);

std::cout << "KILLING ZOMBIES" << std::endl;
	kill_zombies(*database, *orchest);

	for (std::vector<ClientId>::iterator it = all_unclients->begin(); it != all_unclients->end(); it++)
	{
		Unregistered *client = database->get_unregistered_from_fd(it->Fd());
		while (client->msg_out.msg_q_size() > 0)
			orchest->send_msgs(client->Id().Fd());
	}
	delete all_unclients;

	delete database;
	delete orchest;
	delete server_info;

std::cout << "---------BYE BYE PEOPLE---------" << std::endl;
	exit(0);
}
