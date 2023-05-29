#include "../tests.hpp"

int main()
{
	try {
		MessageParameterValidator::validate_key("  \x00 \x06 \x09 \x0A \x0B \x20");
	} catch (MessageParameterValidator::ErroneousKeyException &e) {
		return (0);
	}
	return (-1);
}
