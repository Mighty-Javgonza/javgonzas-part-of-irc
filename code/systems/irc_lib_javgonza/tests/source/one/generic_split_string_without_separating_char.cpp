#include "../../../code/source/all_headers.hpp"
#include <iostream>
#include <array>
#include <vector>

int main()
{
	std::string	splitable = "hola";
	std::vector< std::vector<char> > split_string;
	
	split_string = generic_split(splitable, ',');
	std::string first_string(split_string[0].begin(), split_string[0].end());
	if (first_string != "hola")
		return (-1);
	return (0);
}
