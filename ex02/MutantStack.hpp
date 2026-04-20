#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef std::stack<T, Container>						stack_type;
		typedef typename stack_type::container_type				container_type;
		typedef typename container_type::iterator				iterator;
		typedef typename container_type::const_iterator			const_iterator;
		typedef typename container_type::reverse_iterator		reverse_iterator;
		typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack() : stack_type()
		{
		}

		MutantStack(const MutantStack& other) : stack_type(other)
		{
		}

		MutantStack& operator=(const MutantStack& other)
		{
			stack_type::operator=(other);
			return *this;
		}

		~MutantStack()
		{
		}

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		}
};

#endif
