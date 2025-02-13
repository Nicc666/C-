/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return(*this);
	this->data = other.data;
	return(*this);
}

PmergeMe::~PmergeMe(void)
{
}

bool PmergeMe::inputerror(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		for(int j = 0; argv[i][j]; j++)
		{
			if ((isdigit(argv[i][j]) == false) && (argv[i][j] != ' ') && (argv[i][j] != '+') && (argv[i][j] != '-'))
				return (false);
		}
	}
	return (true);
}

void PmergeMe::printlist(void)
{
	std::vector<int>::iterator it;
	it = data.begin();
	for (; it != data.end(); it++)
		std::cout << *it << std::endl;
	return;
}

bool PmergeMe::fillin(char **argv)
{
	long int x;
	for (int i = 1; argv[i]; i++)
	{
		x = strtol(argv[i], NULL, 10);
		if (x > INT_MAX || x < INT_MIN)
		{
			std::cout << "Error: invalid number" << std::endl;
			return(false);
		}
		data.push_back(x);
	}
	return(true);
}

void PmergeMe::algoritm(char **argv)
{
	if (!this->fillin(argv))
		return;
	std::vector<std::pair<int, int>> p;
	p.reserve(data.size()/2);
	std::vector<int>::iterator it;
	for(it=data.begin(); it!=data.end(); it++)
	{

	}
	this->printlist();
	return;
}
