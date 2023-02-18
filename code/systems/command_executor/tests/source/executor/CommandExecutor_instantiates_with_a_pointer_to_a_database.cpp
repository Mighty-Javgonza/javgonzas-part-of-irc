#include "../tests.hpp"

class	MockDB : public DatabasableMock {
};



int main()
{
	MockDB	*db = new MockDB();

	CommandExecutor command_executor((Databasable *)db);

	if (command_executor.database != (Databasable *)db)
		return (-1);
	return (0);
}
