#include "../tomartin/inc/com.hpp"
#include "../vicmarti/src/db/Database.hpp"
#include "../command_executor/code/source/all_headers.hpp"
#include "../tomartin/inc/orchestator.hpp"
#include "../input_stream_orquestator/CommandActionAssociator.hpp"
#include "../tomartin/inc/ft_ircserv.hpp"
#include "../lexer/code/source/all_headers.hpp"

void	update_listener(orchestator &orchest, Database &db)
{
	orchest.preparation_com(); 
	orchest.accept_new_connect();
//	orchest.orchestation();
//	orchest.check_status();
//	orchest.clean_up();
}

void	process_one_message_from_each_queue(Database &database, orchestator &orchest, ServerInfo &server_info)
{
	std::vector<ClientId> *all_clients = database.get_all_users();
	std::vector<ClientId> *all_unclients = database.UnregisteredClients().Vector();
	LexerParserConnector	parser;
	SentMessage				sent_message;
	replies_generator		rg;


	for (std::vector<ClientId>::iterator it = all_clients->begin(); it != all_clients->end(); it++) 
	{
		orchest.recv_msgs(it->Fd());
		orchest.send_msgs(it->Fd());
		try {
			Client *client = database.get_user_from_fd(it->Fd());
			if (client->msg_in.msg_q_size() != 0)
			{
  				std::string message = client->msg_in.extract_msg();
				client->msg_in.pop_msg();
				if (message != "")
				{
					sent_message.message = parser.parse_string(message);
					if (sent_message.message != NULL)
					{
						sent_message.sender = &(*it);
						CommandActionAssociator::command_function	executor = commandActionAssociator.get_executor(sent_message.message->command);
						executor(&database, &sent_message, &rg, &server_info);
std::cout << "EXECUTED A COMMAND FOR: " << it->Fd() << std::endl;
					}
				}
			}
		} catch(MessageLexer::MissingCommandException) {
std::cout << "This is fine" << std::endl;
		} catch (std::exception &e) {
std::cout << "SOMETHING IS NOT" << std::endl;
std::cout << e.what() << std::endl;
		}
	}

	for (std::vector<ClientId>::iterator it = all_unclients->begin(); it != all_unclients->end(); it++) 
	{
		orchest.recv_msgs(it->Fd());
		orchest.send_msgs(it->Fd());
		try {
			Unregistered *client = database.get_unregistered_from_fd(it->Fd());
			if (client->msg_in.msg_q_size() != 0)
			{
  				std::string message = client->msg_in.extract_msg();
				client->msg_in.pop_msg();
				if (message != "")
				{
					sent_message.message = parser.parse_string(message);
					if (sent_message.message != NULL)
					{
						sent_message.sender = &(*it);
						CommandActionAssociator::command_function	executor = commandActionAssociator.get_executor(sent_message.message->command);
						executor(&database, &sent_message, &rg, &server_info);
std::cout << "EXECUTED A COMMAND FOR: " << it->Fd() << std::endl;
					}
				}
			}
		} catch(MessageLexer::MissingCommandException) {
std::cout << "This is fine" << std::endl;
		} catch (std::exception &e) {
std::cout << "SOMETHING IS NOT" << std::endl;
std::cout << e.what() << std::endl;
		}
	}
	delete all_clients;
	delete all_unclients;
}

void	send_first_message_of_one_client(orchestator &orchest, Client *client)
{
	int send_leng;
	int	cfd = client->Id().Fd();

	if(client->msg_out.msg_q_size() == 0)
		return;
	if(!(orchest.get_event(cfd) & POLLOUT) || (orchest.get_revent(cfd) & POLLOUT)) 
   {
		send_leng = orchest.send_msg(cfd, client->msg_out.extract_msg());
		if(send_leng < client->msg_out.msg_front_len())
			client->msg_out.erase_front_msg(send_leng);
		else
		    client->msg_out.pop_msg();
			if(orchest.get_revent(cfd) & POLLOUT)
				orchest.set_value_poll_list(cfd, POLLIN);
    }
}

void	process_one_reply_from_each_queue(Databasable &database, orchestator &orchest)
{
	std::vector<ClientId> *all_clients = database.get_all_users();

	for (std::vector<ClientId>::iterator it = all_clients->begin(); it != all_clients->end(); it++) 
	{
		Client	*client = database.get_user_from_fd(it->Fd());
		send_first_message_of_one_client(orchest, client);
	}
	delete all_clients;
}

void	update_ping_pong_of_client(Database &database, Client *client, ServerInfo &server_info)
{
	client->user_times.check_if_kick();

	if (client->user_times.get_kick())
	{
		//TODO: DO
//		if (database.Clients().IdExists(client->Id()))
//			kill_registered_client(&database, client);
//		else
//			kill_unregistered_client(&database, client);
	}
	else if (client->user_times.launch_send_ping() &&
		client->user_times.get_s_ping() == false)
	{
		client->msg_out.direct_push(std::string(":" + server_info.get_preffix_string() + " PING" + "\x0d\x0a"));
		client->user_times.launch_t_ping();
		client->user_times.set_s_ping(true);
	}
}

void	update_pinger_ponger(Database &database, ServerInfo &server_info)
{
	std::vector<ClientId> *all_clients = database.get_all_users();

	for (std::vector<ClientId>::iterator it = all_clients->begin(); it != all_clients->end(); it++) 
	{
		Client *client = database.get_user_from_fd(it->Fd());
		update_ping_pong_of_client(database, client, server_info);
	}
	delete all_clients;
}

void	main_loop(int port)
{
	Database	database;
	orchestator	orchest(port, database);
	ServerInfo	server_info;

std::cout << "SERVER IS UP" << std::endl;
	while (true)
	{
		update_listener(orchest, database);
		process_one_message_from_each_queue(database, orchest, server_info);
//	update_database(database);
//	update_pinger_ponger(database, server_info);
//	process_one_reply_from_each_queue(database, orchest);
		usleep(300000);	
	}
}

int main(int argc, char **argv)
{
	int port = atoi(argv[1]);
	main_loop(port);
}
