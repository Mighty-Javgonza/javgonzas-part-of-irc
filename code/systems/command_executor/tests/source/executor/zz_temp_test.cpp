#include "../tests.hpp"

class	MockDB : public Databasable {
	void	set_nick(user *usr, std::string nick) {
		(void)usr;
		(void)nick;
	}
};

int main()
{
	MockDB	*db = new MockDB();

	CommandExecutor command_executor(db);

	if (command_executor.database != (Databasable *)db)
		return (-1);
	return (0);
}
