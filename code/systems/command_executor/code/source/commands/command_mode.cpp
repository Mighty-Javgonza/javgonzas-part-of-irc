#include "commands.hpp"

void	command_mode(Databasable *database, SentMessage *message, replies_generator *replier, ServerInfo *server_info)
{
	(void)replier;
	ParsedMessageConnectionMode	*mode_msg = static_cast<ParsedMessageConnectionMode*>(message->message);
	User *user = database->get_user_from_nickname(mode_msg->nickname);	

	if (user == NULL)
		return ;
	if (!mode_msg->intends_to_change_modes)
	{
		*user << (":" + server_info->get_preffix_string() + " MODE " + mode_msg->nickname + " " + user->get_modes_string() + "\x0d\x0a");
		return ;
	}
	else
	{
		if (mode_msg->mode_i == ParsedMessageConnectionMode::ADD_MODE)
			if (user->modes.invisible == false)
				user->modes.invisible = true;
		if (mode_msg->mode_w == ParsedMessageConnectionMode::ADD_MODE)
			if (user->modes.receive_wallops== false)
				user->modes.receive_wallops= true;
		if (mode_msg->mode_r == ParsedMessageConnectionMode::ADD_MODE)
			if (user->modes.restricted_user_connection == false)
				user->modes.restricted_user_connection = true;
		if (mode_msg->mode_s == ParsedMessageConnectionMode::ADD_MODE)
			if (user->modes.server_notices== false)
				user->modes.server_notices = true;
		if (mode_msg->mode_i == ParsedMessageConnectionMode::REMOVE_MODE)
			if (user->modes.invisible == true)
				user->modes.invisible = false;
		if (mode_msg->mode_w == ParsedMessageConnectionMode::REMOVE_MODE)
			if (user->modes.receive_wallops== true)
				user->modes.receive_wallops= false;
		if (mode_msg->mode_o == ParsedMessageConnectionMode::REMOVE_MODE)
			if (user->modes.is_operator == true)
				user->modes.is_operator = false;
		if (mode_msg->mode_O == ParsedMessageConnectionMode::REMOVE_MODE)
			if (user->modes.local_operator == true)
				user->modes.local_operator = false;
		if (mode_msg->mode_s == ParsedMessageConnectionMode::REMOVE_MODE)
			if (user->modes.server_notices== true)
				user->modes.server_notices = false;
	}
}
