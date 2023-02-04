class CommandExecutor;

#ifndef COMMANDEXECUTOR_HPP
# define COMMANDEXECUTOR_HPP

#include "../Databasable.hpp"

class CommandExecutor {

public:

	Databasable	*database;

	CommandExecutor(Databasable *db);
	~CommandExecutor();

private:

};

#endif
