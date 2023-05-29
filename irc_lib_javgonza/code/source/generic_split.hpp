
#include <iostream>
#include <vector>

template <class ContainerType, typename ElementType>
std::vector< std::vector<ElementType> >	generic_split(ContainerType container, ElementType key)
{
	std::vector< std::vector<ElementType> > double_vector;
	std::vector<ElementType>	current_split;
	typedef typename ContainerType::iterator c_iterator;

	for (c_iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == key)
		{
			double_vector.push_back(current_split);
			current_split.clear();
		}
		else
			current_split.push_back(*it);
	}
	double_vector.push_back(current_split);
	return (double_vector);
}
