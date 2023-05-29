class CommandExecutor;

#ifndef COMMANDEXECUTOR_HPP
# define COMMANDEXECUTOR_HPP

#include "../../../../database/db/Databasable.hpp"

class CommandExecutor {

public:

	Databasable	*database;

	CommandExecutor(Databasable *db);
	~CommandExecutor();

private:

};

#endif
