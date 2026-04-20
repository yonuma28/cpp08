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

	unsigned int shortest = static_cast<unsigned int>(
		static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]));

	for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(
			static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));

		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error("Span: not enough values to compute a span");

	int minValue = _values[0];
	int maxValue = _values[0];

	for (std::vector<int>::size_type i = 1; i < _values.size(); ++i)
	{
		if (_values[i] < minValue)
			minValue = _values[i];
		if (_values[i] > maxValue)
			maxValue = _values[i];
	}

	return static_cast<unsigned int>(
		static_cast<long>(maxValue) - static_cast<long>(minValue));
}
