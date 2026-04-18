#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "easyfind.hpp"

template <typename T>
static void printFound(const T& container, int value, const std::string& label)
{
	try
	{
		typename T::const_iterator it = easyfind(container, value);
		std::cout << label << ": found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << label << ": " << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(-2);
	numbers.push_back(42);
	numbers.push_back(7);

	std::list<int> linked;
	linked.push_back(5);
	linked.push_back(15);
	linked.push_back(25);

	std::deque<int> queue;
	queue.push_back(3);
	queue.push_back(6);
	queue.push_back(9);

	printFound(numbers, 42, "vector");
	printFound(numbers, 99, "vector");
	printFound(linked, 15, "list");
	printFound(linked, -15, "list");
	printFound(queue, 3, "deque");
	printFound(queue, 4, "deque");
	return 0;
}
