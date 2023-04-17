#include "commands.hpp"

void	command_mode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionMode	*mode_msg = static_cast<ParsedMessageConnectionMode*>(message->message);
	Client *client = database->get_user_from_nickname(mode_msg->nickname);	

	if (client == NULL)
		return ;
	if (!mode_msg->intends_to_change_modes)
	{
		*client << (":" + server_info->get_preffix_string() + " MODE " + mode_msg->nickname + " " + client->ModeString() + "\x0d\x0a");
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
				client->Mode(ClientData::Operator, false);
					//TODO: Await for implementation
//		if (mode_msg->mode_O == ParsedMessageConnectionMode::REMOVE_MODE)
//			if (client->modes.local_operator == true)
//				client->modes.local_operator = false;
		if (mode_msg->mode_s == ParsedMessageConnectionMode::REMOVE_MODE)
			if (client->Mode(ClientData::ServerNotice) == true)
				client->Mode(ClientData::ServerNotice, false);
	}
}
