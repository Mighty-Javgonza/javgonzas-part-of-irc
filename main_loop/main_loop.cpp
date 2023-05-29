#include "../sockets/inc/com.hpp"
#include "../database/db/Database.hpp"
#include "../command_executor/code/source/all_headers.hpp"
#include "../sockets/inc/orchestator.hpp"
#include "../input_stream_orquestator/CommandActionAssociator.hpp"
#include "../sockets/inc/ft_ircserv.hpp"
#include "../lexer/code/source/all_headers.hpp"
#include "main_loop.hpp"

replies_generator		rg;

void  signal_handler(int)
{
	std::cout << "A client exited rudely" << std::endl;
}

Database *database_ref;
ServerInfo *server_info_ref;
orchestator *orchestator_ref;

void  signal_server_shutdown(int sig)
{
	(void)sig;
	server_shutdown(database_ref, orchestator_ref, server_info_ref);
}

void	update_listener(orchestator &orchest)
{
	orchest.preparation_com();
	orchest.accept_new_connect();
	orchest.delete_users_from_list();
}

void	process_first_message_of_client_data(Database &database, ServerInfo &server_info, ClientData *client)
{
	SentMessage				sent_message;

	if (client->msg_in.msg_q_size() != 0)
	{
		std::string message = client->msg_in.extract_msg();
		client->msg_in.pop_msg();
		if (message != "")
		{
std::cout << "   ->" << message << "<-" << std::endl;
			LexerParserConnector	parser;
			try
			{
				sent_message.message = NULL;
				sent_message.message = parser.parse_string(message);
			} catch (std::exception &e) {
				*client << ":" + server_info.get_preffix_string() + " ERROR :" + e.what() + "\r\n";
				if (sent_message.message != NULL)
					delete sent_message.message;
				return ;
			}
			if (sent_message.message != NULL)
			{
				client->user_times.reset_t_last_msg();
				sent_message.sender = (ClientId *)&client->Id();
				CommandActionAssociator::command_function	executor = commandActionAssociator.get_executor(sent_message.message->command);
				bool already_registered = database.Clients().IdExists(client->Id());
				if (already_registered)
					rg.target_string = client->Id().FullHostname();
				if (!already_registered && !commandActionAssociator.is_unregistered_executable(executor))
					*client << ":" + server_info.get_preffix_string() + " ERROR :You are not registered. You can't use that command\r\n";
				else
				{
					executor(&database, &sent_message, &rg, &server_info);
					server_info.count_command(sent_message.message->command, message);
				}
				delete sent_message.message;
			}
			else
			{
				*client << ":" + server_info.get_preffix_string() + " ERROR :Command not recognised\r\n";
			}
		}
	}
}

void update_user_queues_and_receive_events(orchestator &orchest, int fd, Database &database)
{
	orchest.recv_msgs(fd);
	orchest.send_msgs(fd);

	if (orchest.get_revent(fd) & POLLHUP)
	{
		ClientData *cd = database.get_client_data_from_fd(fd);
		if (database.Clients().IdExists(cd->Id()))
			cd->msg_in.add_msg("QUIT\r\n");
		else
			orchest.kill_list.push(std::make_pair(fd, std::string("POLLHUP")));
	}
}

static void	process_one_message_of_each_client_of_client_id_vector(std::vector<ClientId> *clients, Database &database, orchestator &orchest, ServerInfo &server_info)
{
	for (std::vector<ClientId>::iterator it = clients->begin(); it != clients->end(); it++) 
	{
		update_user_queues_and_receive_events(orchest, it->Fd(), database);
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

void	send_ping(ClientData *client, ServerInfo &server_info)
{
//	client->msg_out.add_msg(std::string(":" + server_info.get_preffix_string() + " PING " + server_info.get_preffix_string() + "\r\n"));
	client->msg_out.add_msg(std::string("PING "+ server_info.get_preffix_string() +"\r\n"));
	client->user_times.launch_t_ping();
}

void	update_ping_pong_of_client(ClientData *client, ServerInfo &server_info)
{
	client->user_times.check_if_kick_logged();

	if (client->user_times.get_kick() == KICK)
	{
		client->msg_in.add_msg("QUIT\r\n");
	}
	else if (client->user_times.launch_send_ping() && client->user_times.get_s_ping() == false)
		send_ping(client, server_info);
}

void	update_ping_pong_of_unclient(Database &database, ClientData *client, ServerInfo &server_info, orchestator &orchest)
{
	client->user_times.check_if_kick_not_logged();

	if (client->user_times.get_kick() == KICK)
	{
		orchest.kill_list.push(std::make_pair(client->Id().Fd(), std::string("REGISTER TIMEOUT")));
		database.UnregisteredClients().Remove(client->Id());
	}
	else if (client->user_times.launch_send_ping() && client->user_times.get_s_ping() == false)
		send_ping(client, server_info);
}

void	update_pinger_ponger(Database &database, ServerInfo &server_info, orchestator &orchest)
{
	std::vector<ClientId> *all_clients = database.get_all_users();

	for (std::vector<ClientId>::iterator it = all_clients->begin(); it != all_clients->end(); it++) 
	{
		ClientData *client = database.get_client_data_from_fd(it->Fd());
		update_ping_pong_of_client(client, server_info);
	}
	delete all_clients;

	std::vector<ClientId> *all_unclients = database.UnregisteredClients().Vector();
	for (std::vector<ClientId>::iterator it = all_unclients->begin(); it != all_unclients->end(); it++) 
	{
		ClientData *client = database.get_client_data_from_fd(it->Fd());
		update_ping_pong_of_unclient(database, client, server_info, orchest);
	}
	delete all_unclients;
}

void kill_zombies(Database &database, orchestator &orchest)
{
	std::vector<ClientId> *zombies = database.get_zombies();

	for (size_t i = 0; i < zombies->size(); i++)
	{
		Client *zombie = database.get_zombie((*zombies)[i]);

		std::vector<ChanId> *subscribed_channels = zombie->Subscriptions();

		for (size_t i = 0; i < subscribed_channels->size(); i++)
		{
			Chan	*channel = database.get_channel_from_id((*subscribed_channels)[i]);
			part_user_from_chan(zombie, zombie, channel, false, "", &database);
		}
		delete subscribed_channels;
		size_t msgs_length = zombie->msg_out.msg_q_size();
		for (size_t j = 0; j < msgs_length; j++)
		{
			orchest.send_msgs(zombie->Id().Fd());
		}
		orchest.kill_list.push(std::make_pair(zombie->Id().Fd(), std::string("QUIT")));
		database.douse_in_holy_water(zombie->Id());
	}
	delete zombies;
}

void	main_loop(int port, std::string password)
{
	database_ref = new Database();
	orchestator_ref = new orchestator(port, *database_ref);
	server_info_ref = new ServerInfo();

	Database &database = *database_ref;
	ServerInfo &server_info = *server_info_ref;
	orchestator &orchest= *orchestator_ref;

	if (password != "")
		server_info.has_password = true;
	else
		server_info.has_password = false;
	server_info.password = password;
	server_info.oper_name = "admin";
	server_info.oper_password = "admin";

	server_info.version = "0.9";
	server_info.debug_lvl= "BEGGINING";
	server_info.comment = "This is definitely a server";
	server_info.motd= "Quien tenga miedo a vivir, que no nazca.";

	rg.hostname = server_info.hostname;

std::cout << "SERVER IS UP on hostname: " << server_info.hostname << std::endl;
	size_t loops = 0;
	while (true)
	{
		update_listener(orchest);
		kill_zombies(database, orchest);
		process_one_message_from_each_queue(database, orchest, server_info);
		update_pinger_ponger(database, server_info, orchest);
		loops++;
		std::cout << '\r';
		std::cout << std::setw(10) << loops << "    " << std::flush;
	}
}


int main(int argc, char **argv)
{
	try {
		std::pair<int, std::string> args = parse_arg(argc, argv);
		signal(SIGINT, signal_server_shutdown);
		signal(SIGPIPE, signal_handler);
		main_loop(args.first, args.second);
	} catch (com_exceptions const &) {
		std::cerr << "Could not start server communications" << std::endl;
	} catch (std::exception const &e) {
		std::cerr << "Unexpected error" << std::endl;
	}
}
