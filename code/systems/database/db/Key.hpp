#ifndef KEY_HPP
# define KEY_HPP

# include <string>

class Key
{
public:
	static bool	Match(Key const &lhs, Key const &rhs);

	Key(void);
	Key(std::string const& key);
	Key(Key const &rhs);
	~Key(void);
	Key	&operator=(Key const &);
private:
	std::string	__key;
};
#endif

