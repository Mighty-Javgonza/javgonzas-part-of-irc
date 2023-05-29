#include "../tests.hpp"

int main()
{
	std::string	hostname = "";

	for (int i = 0; i < 64; i++)
		hostname += "a";
	try {
		MessageParameterValidator::validate_hostname(hostname);
	} catch (MessageParameterValidator::ErroneousHostnameException) {
		return (0);
	}
	return (-1);
}
