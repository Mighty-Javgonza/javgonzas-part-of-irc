#include "commands.hpp"

//The optional quit message is not tested
static void	relay_quit_to_users_in_shared_channels(Databasable *database, User *user, ParsedMessageConnectionQuit *quit_msg)
{
	(void)database;
	(void)user;
	(void)quit_msg;
//	std::vector <Channel *> user_channels = database->get_channels_of_user(user);
//	std::string user_preffix = ":" + user->get_preffix_string();



//	std::string relay_quit_msg;
//	if (quit_msg->has_quit_message)
//		relay_quit_msg = user_preffix + " QUIT :" + quit_msg->quit_message + "\r\n";
//	else
//		relay_quit_msg = user_preffix + " QUIT\r\n";
//
//	for (std::vector<Channel *>::iterator it = user_channels.begin(); it != user_channels.end(); it++)
//
//	for (std::vector<User>::iterator it = all_users.begin(); it != all_users.end(); it++)
//		*it << relay_quit_msg;
}

void	command_quit(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionQuit	*quit_msg = static_cast<ParsedMessageConnectionQuit*>(message->message);
	User *user = database->get_user_from_fd(message->sender->fd);

	*user << ":" + server_info->get_preffix_string() + " ERROR :Your connection was closed\r\n";
	database->kill_user(message->sender);
	relay_quit_to_users_in_shared_channels(database, user, quit_msg);
}
