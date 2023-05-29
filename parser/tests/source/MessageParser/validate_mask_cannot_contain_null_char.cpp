#include "../tests.hpp"

int main()
{
	std::string	mask_candidate = "abc";
	mask_candidate[1] = '\0';
	try {
		MessageParameterValidator::validate_mask(mask_candidate);
	} catch (MessageParameterValidator::ErroneousMaskException &e) {
		return (0);
	}
	return (-1);
}
