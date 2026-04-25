#include <iostream>
#include <list>
#include <stdexcept>

#include "MutantStack.hpp"

static void testSubjectExample()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "ms.stack.pop : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "msstack.size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	(void)s;
}

static void compareWithList()
{
	MutantStack<int> mstack;
	std::list<int> reference;
	int values[] = {10, 20, 30, 40};

	for (int i = 0; i < 4; ++i)
	{
		mstack.push(values[i]);
		reference.push_back(values[i]);
	}

	MutantStack<int>::const_iterator it = mstack.begin();
	std::list<int>::const_iterator refIt = reference.begin();
	while (it != mstack.end() && refIt != reference.end())
	{
		std::cout << "mutant=" << *it << ", list=" << *refIt << std::endl;
		++it;
		++refIt;
	}
}

static void testInvalidUse()
{
	MutantStack<int> empty;

	try
	{
		if (empty.empty())
			throw std::logic_error("MutantStack: top() on empty stack is invalid");
		std::cout << empty.top() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	testSubjectExample();
	compareWithList();
	testInvalidUse();
	return 0;
}
