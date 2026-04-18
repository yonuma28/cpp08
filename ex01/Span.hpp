#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

class Span
{
private:
	unsigned int			_maxSize;
	std::vector<int>		_values;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int value);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end)
	{
		std::vector<int> buffer;
		for (InputIterator it = begin; it != end; ++it)
			buffer.push_back(*it);
		if (_values.size() + buffer.size() > _maxSize)
			throw std::out_of_range("Span: range exceeds capacity");
		_values.insert(_values.end(), buffer.begin(), buffer.end());
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif
