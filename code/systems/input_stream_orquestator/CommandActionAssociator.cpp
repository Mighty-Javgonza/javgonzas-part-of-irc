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
//TODO: mode is also an exception for command execution
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

CommandActionAssociator	commandActionAssociator;
