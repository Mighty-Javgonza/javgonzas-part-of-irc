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
	orchest.check_status();
	orchest.clean_up();
}

void	process_first_message_of_client_data(Database &database, ServerInfo &server_info, ClientData *client)
{
	SentMessage				sent_message;
	replies_generator		rg;

	if (client->msg_in.msg_q_size() != 0)
	{
		std::string message = client->msg_in.extract_msg();
		client->msg_in.pop_msg();
		if (message != "")
		{
std::cout << "MESSAGE RECEIVED   ->" << message << "<-" << std::endl;
			//TODO Instanciar solo una vez
			LexerParserConnector	parser;
			sent_message.message = parser.parse_string(message);
			if (sent_message.message != NULL)
			{
				sent_message.sender = (ClientId *)&client->Id();
				CommandActionAssociator::command_function	executor = commandActionAssociator.get_executor(sent_message.message->command);
				executor(&database, &sent_message, &rg, &server_info);
			}
			else
			{
				*client << ":" + server_info.get_preffix_string() + " ERROR :Command not recognised\r\n";
			}
		}
	}
}

void update_user_queues_and_receive_events(orchestator &orchest, int fd)
{
	orchest.recv_msgs(fd);
	orchest.send_msgs(fd);

	if (orchest.get_revent(fd) & POLLHUP)
		orchest.kill_list.push(std::make_pair(fd, std::string("POLLHUP")));
}

static void	process_one_message_of_each_client_of_client_id_vector(std::vector<ClientId> *clients, Database &database, orchestator &orchest, ServerInfo &server_info)
{
	for (std::vector<ClientId>::iterator it = clients->begin(); it != clients->end(); it++) 
	{
		update_user_queues_and_receive_events(orchest, it->Fd());
		try {
			ClientData *client = database.get_client_data_from_fd(it->Fd());
			process_first_message_of_client_data(database, server_info, client);
		} catch(MessageLexer::MissingCommandException) {
			std::cout << "This is fine" << std::endl;
		} catch (std::exception &e) {
			std::cout << "SOMETHING IS NOT" << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
}

void	process_one_message_from_each_queue(Database &database, orchestator &orchest, ServerInfo &server_info)
{
	std::vector<ClientId> *all_clients = database.get_all_users();
	process_one_message_of_each_client_of_client_id_vector(all_clients, database, orchest, server_info);	
	delete all_clients;

	std::vector<ClientId> *all_unclients = database.UnregisteredClients().Vector();
	process_one_message_of_each_client_of_client_id_vector(all_unclients, database, orchest, server_info);
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

	server_info.oper_name = "admin";
	server_info.oper_password = "admin";
	server_info.has_password = true;
	server_info.password = "1234";

std::cout << "SERVER IS UP" << std::endl;
	while (true)
	{
		update_listener(orchest, database);
		process_one_message_from_each_queue(database, orchest, server_info);
//	update_database(database);
//	update_pinger_ponger(database, server_info);
//	process_one_reply_from_each_queue(database, orchest);
	}
}

int main(int argc, char **argv)
{
	int port = atoi(argv[1]);
	main_loop(port);
}
