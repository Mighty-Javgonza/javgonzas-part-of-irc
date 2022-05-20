class LexedMessage;

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

#include <iostream>
#include <vector>

class LexedMessage {

public:
	LexedMessage();
	~LexedMessage();

	bool	checkHasPreffix();
	bool	checkHasCommand();
	bool	checkHasTrailing();

	std::string	getPreffix();
	std::string	getCommand();
	std::string	getTrailing();

	void	setPreffix(std::string str);
	void	setCommand(std::string str);
	void	setTrailing(std::string str);
	std::vector<std::string>	parameters;

	void	printDebug();

private:
	std::string preffix;
	bool hasPreffix;
	std::string command;
	bool hasCommand;
	std::string trailing;
	bool hasTrailing;

};

#endif
