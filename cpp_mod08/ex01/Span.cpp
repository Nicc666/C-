/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::vector<int> v(0);
	max = 0;
}

Span::Span(unsigned int n)
{
	std::vector<int> v(n);
	max = n;
}

Span::Span(const Span &other)
{
	std::vector<int> v(0);
	max = 0;
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->max = other.max;
	this->v = other.v;
	return(*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (this->v.size() == this->max)
		throw Span::OutlimitsException();
	this->v.push_back(number);
}

int Span::shortestSpan(void)
{
	if (this->v.size() < 2)
		throw Span::spanException();
	int v_diff = 0;
	int v_diff_min = INT_MAX;
	std::vector<int> v_copy = this->v;
	std::sort(v_copy.begin(), v_copy.end());
	for (size_t i=0; ((i+1) < v_copy.size()); i++)
	{
		v_diff = v_copy[i+1] - v_copy[i];
		if (v_diff < v_diff_min)
			v_diff_min = v_diff;
	}
	return(v_diff_min);
}

int Span::longestSpan(void)
{
	if (this->v.size() < 2)
		throw Span::spanException();
	int span_max;
	std::vector<int> v_copy = this->v;
	std::sort(v_copy.begin(), v_copy.end());
	span_max = (v_copy[v_copy.size() - 1]) - v_copy[0];
	return(span_max);
}

int Span::getvnum(int i)
{
	return(this->v[i]);
}

void Span::printvector(void)
{
	std::vector<int>::iterator it = this->v.begin();
	for (; it != this->v.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void Span::insertmanynum(std::vector<int> v2)
{
	if (this->v.size() + v2.size() == this->max || v2.size() == 0)
		throw Span::OutlimitsException();
	this->v.insert(this->v.end(), v2.begin(), v2.end());
}
