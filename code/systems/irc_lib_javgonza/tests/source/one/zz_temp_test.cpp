#include "../../../code/source/all_headers.hpp"
#include <iostream>
#include <array>
#include <vector>

int main()
{
	std::string	splitable = "hola,adios,";
	std::vector< std::vector<int> > split_result;

	std::array<int, 7> arr = {1, 2, 3, -1, 4, 5, 6};
	
	split_result = generic_split(arr, -1);
	std::vector<int> first_group(split_result[0].begin(), split_result[0].end());
	if (first_group[0] != 1)
		return (-1);
	return (0);
}
