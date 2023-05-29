#include "commands.hpp"

void	relay_to_all_users(const std::string &mode, const std::string &nickname, Databasable *database, ServerInfo *server_info)
{
	std::vector<ClientId>	*all_users = database->get_all_users();
	std::string	relay_message = ":" + server_info->get_preffix_string() + " MODE " + nickname + " " + mode + "\r\n";

	for (std::vector<ClientId>::iterator it = all_users->begin(); it != all_users->end(); it++)
	{
		Client	*client = database->get_user_from_fd(it->Fd());	

		*client << relay_message;
	}
}

void	command_mode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionMode	*mode_msg = static_cast<ParsedMessageConnectionMode*>(message->message);
	Client	*requester = database->get_user_from_fd(message->sender->Fd());
	Client *client = database->get_user_from_nickname(requester, mode_msg->nickname);

	if (client == NULL)
	{
		*requester << replier->mode_nosuchnick(mode_msg->nickname);
		return ;
	}
	if (!mode_msg->intends_to_change_modes)
	{
		*requester << (":" + server_info->get_preffix_string() + " MODE " + mode_msg->nickname + " " + client->ModeString() + "\r\n");
		return ;
	}
	else
	{
		if (mode_msg->mode_i == ParsedMessageConnectionMode::ADD_MODE)
			if (client->Mode(ClientData::Invisible) == false)
				client->Mode(ClientData::Invisible, true);
		if (mode_msg->mode_w == ParsedMessageConnectionMode::ADD_MODE)
			if (client->Mode(ClientData::Wallops) == false)
				client->Mode(ClientData::Wallops, true);
					//TODO: Delete if it won't be implemented
//		if (mode_msg->mode_r == ParsedMessageConnectionMode::ADD_MODE)
//			if (client->modes.restricted_user_connection == false)
//				client->modes.restricted_user_connection = true;
		if (mode_msg->mode_s == ParsedMessageConnectionMode::ADD_MODE)
			if (client->Mode(ClientData::ServerNotice) == false)
				client->Mode(ClientData::ServerNotice, true);
		if (mode_msg->mode_i == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::Invisible) == true)
				client->Mode(ClientData::Invisible, false);
		if (mode_msg->mode_w == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::Wallops) == true)
				client->Mode(ClientData::Wallops, false);
		if (mode_msg->mode_o == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::Operator) == true)
			{
				client->Mode(ClientData::Operator, false);
				relay_to_all_users("-o", client->Nick(), database, server_info);
			}
		if (mode_msg->mode_O == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::LocalOperator) == true)
			{
				client->Mode(ClientData::LocalOperator, false);
				relay_to_all_users("-O", client->Nick(), database, server_info);
			}
		if (mode_msg->mode_s == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::ServerNotice) == true)
				client->Mode(ClientData::ServerNotice, false);
	}
}
