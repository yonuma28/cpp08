#include "Span.hpp"

Span::Span() : _maxSize(0), _values()
{
}

Span::Span(unsigned int n) : _maxSize(n), _values()
{
	_values.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _values(other._values)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_values = other._values;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
	if (_values.size() >= _maxSize)
		throw std::out_of_range("Span: container is full");
	_values.push_back(value);
}

unsigned int Span::shortestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error("Span: not enough values to compute a span");

	std::vector<int> sorted(_values);
	std::sort(sorted.begin(), sorted.end());

	unsigned long shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		unsigned long diff = static_cast<unsigned long>(
			static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));
		if (diff < shortest)
			shortest = diff;
	}
	return static_cast<unsigned int>(shortest);
}

unsigned int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error("Span: not enough values to compute a span");

	int minValue = *std::min_element(_values.begin(), _values.end());
	int maxValue = *std::max_element(_values.begin(), _values.end());
	return static_cast<unsigned int>(
		static_cast<long>(maxValue) - static_cast<long>(minValue));
}
