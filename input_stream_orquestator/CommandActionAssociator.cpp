#include "CommandActionAssociator.hpp"

#include "AllMessageParsers.hpp"
#include "../command_executor/code/source/commands/commands.hpp"

CommandActionAssociator::CommandActionAssociator()
{
	action_map.insert(std::make_pair("NICK", (commandActuators){.parser = new MessageConnectionNickParser, .executor = command_nick}));
	action_map.insert(std::make_pair("USER", (commandActuators){.parser = new MessageConnectionUserParser, .executor = command_user}));
	action_map.insert(std::make_pair("PRIVMSG", (commandActuators){.parser = new MessagePrivateMessagesPrivmsgParser, .executor = command_privmsg}));
	action_map.insert(std::make_pair("NOTICE", (commandActuators){.parser = new MessagePrivateMessagesNoticeParser, .executor = command_notice}));
	action_map.insert(std::make_pair("KILL", (commandActuators){.parser = new MessageUserKillParser, .executor = command_kill}));
	action_map.insert(std::make_pair("OPER", (commandActuators){.parser = new MessageConnectionOperParser, .executor = command_oper}));
	action_map.insert(std::make_pair("MODE", (commandActuators){.parser = new ModeParser, .executor = mixed_command_mode}));
	action_map.insert(std::make_pair("PASS", (commandActuators){.parser = new MessageConnectionPassParser, .executor = command_pass}));
	action_map.insert(std::make_pair("QUIT", (commandActuators){.parser = new MessageConnectionQuitParser, .executor = command_quit}));
	action_map.insert(std::make_pair("PART", (commandActuators){.parser = new MessageChannelPartParser, .executor = command_part}));
	action_map.insert(std::make_pair("TOPIC", (commandActuators){.parser = new MessageChannelTopicParser, .executor = command_topic}));
	action_map.insert(std::make_pair("INVITE", (commandActuators){.parser = new MessageChannelInviteParser, .executor = command_invite}));
	action_map.insert(std::make_pair("KICK", (commandActuators){.parser = new MessageChannelKickParser, .executor = command_kick}));
	action_map.insert(std::make_pair("NAMES", (commandActuators){.parser = new MessageChannelNamesParser, .executor = command_names}));
	action_map.insert(std::make_pair("LIST", (commandActuators){.parser = new MessageChannelListParser, .executor = command_list}));
	action_map.insert(std::make_pair("JOIN", (commandActuators){.parser = new MessageChannelJoinParser, .executor = command_join}));
	action_map.insert(std::make_pair("VERSION", (commandActuators){.parser = new MessageServerVersionParser, .executor = command_version}));
	action_map.insert(std::make_pair("MOTD", (commandActuators){.parser = new MessageServerMotdParser, .executor = command_motd}));
	action_map.insert(std::make_pair("PONG", (commandActuators){.parser = new MessageUserPongParser, .executor = command_pong}));
	action_map.insert(std::make_pair("PING", (commandActuators){.parser = new MessageUserPingParser, .executor = command_ping}));
	action_map.insert(std::make_pair("STATS", (commandActuators){.parser = new MessageServerStatsParser, .executor = command_stats}));
	size_t i = 0;
	for (std::map<std::string, struct commandActuators>::iterator it = action_map.begin(); it != action_map.end(); it++)
	{
		it->second.unique_id = i;
		i++;
	}
	command_count = i;
}

CommandActionAssociator::~CommandActionAssociator()
{

}

MessageParser	*CommandActionAssociator::get_parser(std::string command)
{
	std::map<std::string, struct commandActuators>::iterator found_element;

	found_element = action_map.find(command);
	if (found_element == action_map.end())
		return (NULL); //TODO Throw command not found
	return (found_element->second.parser);
}

CommandActionAssociator::command_function CommandActionAssociator::get_executor(std::string command)
{
	std::map<std::string, struct commandActuators>::iterator found_element;

	found_element = action_map.find(command);
	if (found_element == action_map.end())
		return (NULL); //TODO Throw command not found
	return (found_element->second.executor);
}

bool	CommandActionAssociator::is_unregistered_executable(command_function cf)
{
	return (cf == command_pass ||
			cf == command_nick ||
			cf == command_user ||
			cf == command_ping ||
			cf == command_pong);
}

size_t	CommandActionAssociator::get_command_id(std::string command)
{
	std::map<std::string, struct commandActuators>::iterator found_element;

	found_element = action_map.find(command);
	if (found_element == action_map.end())
		return (command_count + 1000); //TODO  Cause SEGFAULT, Why not?
	return (found_element->second.unique_id);
}

size_t	CommandActionAssociator::get_command_count()
{
	return (command_count);
}

std::string	CommandActionAssociator::get_command_by_id(size_t cid)
{
	size_t i = 0;
	for (std::map<std::string, struct commandActuators>::iterator it = action_map.begin(); it != action_map.end(); it++)
	{
		if (it->second.unique_id == cid)
			return (it->first);
		i++;
	}
	return ("");
}

CommandActionAssociator	commandActionAssociator;
size_t	CommandActionAssociator::command_count = 0;
