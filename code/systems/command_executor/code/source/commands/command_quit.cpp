#include "commands.hpp"

//The optional quit message is not tested
static void	relay_quit_to_users_in_shared_channels(Databasable *database, Client *client, ParsedMessageConnectionQuit *quit_msg)
{
	(void)database;
	(void)client;
	(void)quit_msg;
//	std::vector <Chan *> user_channels = database->get_channels_of_user(client);
//	std::string user_preffix = ":" + client->MessagePrefix();



//	std::string relay_quit_msg;
//	if (quit_msg->has_quit_message)
//		relay_quit_msg = user_preffix + " QUIT :" + quit_msg->quit_message + "\r\n";
//	else
//		relay_quit_msg = user_preffix + " QUIT\r\n";
//
//	for (std::vector<Chan *>::iterator it = user_channels.begin(); it != user_channels.end(); it++)
//
//	for (std::vector<Client *>::iterator it = all_users.begin(); it != all_users.end(); it++)
//		*it << relay_quit_msg;
}

void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionQuit	*quit_msg = static_cast<ParsedMessageConnectionQuit*>(message->message);
	Client *client = database->get_user_from_fd(message->sender->Fd());

	*client << ":" + server_info->get_preffix_string() + " ERROR :Your connection was closed\r\n";
	database->kill_user(client);
	relay_quit_to_users_in_shared_channels(database, client, quit_msg);
}
