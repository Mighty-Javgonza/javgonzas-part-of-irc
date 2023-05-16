#include "commands.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>

static void	send_commands_count(Client *client, replies_generator *replier)
{
	for (size_t i = 0; i < CommandActionAssociator::get_command_count(); i++)
	{
		char buff[30];
		std::sprintf(buff, "%zu", stater.calls_to_commands[i]);
		std::string calls_string = buff;
		std::sprintf(buff, "%zu", stater.bytes_per_command[i]);
		std::string bytes_string = buff;
		*client << replier->stats_m(commandActionAssociator.get_command_by_id(i), calls_string, bytes_string, "*");
	}
	*client << replier->stats_end("m");
}

static void	send_database_get_from_fd_count(Client *client, replies_generator *replier, ServerInfo *server_info)
{
	char buff[30];
	std::sprintf(buff, "%zu", stater.calls_to_database_get_from_fd);
	std::string calls_string = buff;
	*client << ":" + server_info->get_preffix_string() + " database_get_from_fd_calls " + calls_string + "\r\n";
	*client << replier->stats_end("d");
}

static void	send_server_uptime(Client *client, replies_generator *replier, ServerInfo *server_info)
{
	std::chrono::high_resolution_clock::duration time_since_start = std::chrono::high_resolution_clock::now() - server_info->start_time;
	std::chrono::seconds seconds_since_start = std::chrono::duration_cast<std::chrono::seconds>(time_since_start);
	int days = seconds_since_start.count() / (24 * 60 * 60);
	int hours = (seconds_since_start.count() % (24 * 60 * 60)) / (60 * 60);
	int minutes = (seconds_since_start.count() % (60 * 60)) / 60;
	int seconds = seconds_since_start.count() % 60;

	 std::ostringstream oss;

	oss << days << " days " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
	*client << replier->stats_u(oss.str(), "u");
}

void	command_stats(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	ParsedMessageServerStats	*stats_msg = static_cast<ParsedMessageServerStats*>(message->message);
	Client	*client = database->get_user_from_fd(message->sender->Fd());

	if (stats_msg->has_query)
	{
		if (stats_msg->query.command_usage_count)
			send_commands_count(client, replier);
		else if (stats_msg->query.number_of_database_get_from_fd)
			send_database_get_from_fd_count(client, replier, server_info);
		else if (stats_msg->query.display_server_time_alive)
			send_server_uptime(client, replier, server_info);
		else if (stats_msg->query.list_server_connections)
		{
			std::vector<ClientId> *all_users = database->get_all_users();
			for (std::vector<ClientId>::iterator it = all_users->begin(); it != all_users->end(); it++)
			{
				ClientData	*cd = database->get_client_data_from_fd(it->Fd());
				std::chrono::high_resolution_clock::duration time_since_start = std::chrono::high_resolution_clock::now() - server_info->start_time;
				std::chrono::seconds seconds_since_start = std::chrono::duration_cast<std::chrono::seconds>(time_since_start);
				int days = seconds_since_start.count() / (24 * 60 * 60);
				int hours = (seconds_since_start.count() % (24 * 60 * 60)) / (60 * 60);
				int minutes = (seconds_since_start.count() % (60 * 60)) / 60;
				int seconds = seconds_since_start.count() % 60;

				 std::ostringstream oss;

				oss << days << " days " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
				(void)cd;

//TODO				std::string	linkinfo = cd->Id().FullHostname() + " " + cd->msg_out.msg_q_size() + " " + cd->messages_received + " " + cd->kilobytes_received + " " + cd->messages_sent + " " + cd->kilobytes_sent + " " <<  oss;
			}
			*client << replier->stats_end("l");
			delete all_users;
		}
	}
}
