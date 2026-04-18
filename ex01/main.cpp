#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "Span.hpp"

static void printSpan(const Span& span, const std::string& label)
{
	try
	{
		unsigned int shortest = span.shortestSpan();
		std::cout << label << " shortest: " << shortest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << label << " shortest: " << e.what() << std::endl;
	}

	try
	{
		unsigned int longest = span.longestSpan();
		std::cout << label << " longest: " << longest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << label << " longest: " << e.what() << std::endl;
	}
}

int main()
{
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try
		{
			sp.addNumber(12);
		}
		catch (const std::exception& e)
		{
			std::cout << "single add rejection: " << e.what() << std::endl;
		}
	}

	{
		Span small(1);
		small.addNumber(42);
		printSpan(small, "small");
	}

	{
		Span rangeSpan(10000);
		std::vector<int> values;
		values.reserve(10000);
		std::srand(42);
		for (int i = 0; i < 10000; ++i)
			values.push_back(std::rand());
		rangeSpan.addRange(values.begin(), values.end());
		printSpan(rangeSpan, "rangeSpan");
		try
		{
			rangeSpan.addRange(values.begin(), values.begin() + 2);
		}
		catch (const std::exception& e)
		{
			std::cout << "range add rejection: " << e.what() << std::endl;
		}
	}

	{
		Span duplicates(4);
		duplicates.addNumber(8);
		duplicates.addNumber(8);
		duplicates.addNumber(-8);
		duplicates.addNumber(0);
		printSpan(duplicates, "duplicates");
	}

	return 0;
}
