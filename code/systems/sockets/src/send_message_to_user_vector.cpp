void	send_message_to_user_vector(std::vector<User> users, std::string message)
{
	for (std::vector<User>::iterator user_it = users.begin(); user_it != users.end(); user_it++)
		*user_it << message;
}
