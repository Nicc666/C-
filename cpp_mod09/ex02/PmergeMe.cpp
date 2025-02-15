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
	this->p = other.p;
	this->ret = other.ret;
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
			if ((isdigit(argv[i][j]) == false) && (argv[i][j] != '+') && (argv[i][j] != '-'))
				return (false);
			if ((argv[i][j] == '+' || argv[i][j] == '-') && j != 0)
				return (false);
		}
	}
	return (true);
}

void PmergeMe::printlist(std::vector<int> &vec)
{
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return;
}

void PmergeMe::printpair(void)
{
	std::vector<std::pair<int, int> >::iterator it;
	it = p.begin();
	for (; it != p.end(); it++)
		std::cout << "first " << it->first << " second " << it->second << std::endl;
	return;
}

bool PmergeMe::fillint(char **argv)
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

void PmergeMe::fillpair(void)
{
	p.reserve(data.size()/2);
	std::vector<int>::iterator it;
	for(it=data.begin(); it!=data.end(); it++)
	{
		if ((it+1) == data.end())
			break;
		p.push_back(std::make_pair(*it, *(it + 1)));
		it++;
	}
	return;
}

void PmergeMe::orderpair(void)
{
	std::vector<std::pair<int, int> >::iterator it;
	for(it=p.begin(); it!=p.end(); it++)
	{
		if (it->second < it->first)
		{
			std::swap(it->first, it->second);
		}
	}
	return;
}

void PmergeMe::vectorret(std::vector<int> &first, std::vector<int> &second)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it_r;
	for(it=first.begin(); it!=first.end(); it++)
	{
		ret.push_back(*it);
	}
	for(it=second.begin(); it!=second.end(); it++)
	{
		for(it_r=ret.begin(); it_r!=ret.end(); it_r++)
		{
			if ((it_r + 1) != ret.end() && *it <= *(it_r + 1))
			{
				ret.insert(it_r+1, *it);
				break;
			}
			else if ((it_r + 1) == ret.end())
			{
				ret.push_back(*it);
				break;
			}
		}
	}
	return;
}

void PmergeMe::final(void)
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<std::pair<int, int> >::iterator it;
	for(it=p.begin(); it!=p.end(); it++)
	{
		first.push_back(it->first);
		second.push_back(it->second);
	}
	if (data.size() % 2 != 0)
		first.push_back(data.back());
	std::sort(first.begin(), first.end());
	this->vectorret(first, second);
	return;
}

void PmergeMe::algoritm(char **argv)
{
	if (!this->fillint(argv))
		return;
	clock_t start = clock();
	std::cout << "Before: ";
	this->printlist(data);
	if (data.size() <= 3)
	{
		std::sort(data.begin(), data.end());
		std::cout << "After:  ";
		this->printlist(data);
		return;
	}
	this->fillpair();
	this->orderpair();
	this->final();
	clock_t end = clock();
	std::cout << "After:  ";
	this->printlist(ret);
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << data.size() << "elements: " << elapsed*1000000.0 << " us" << std::endl;
	return;
}

/*
bool PmergeMe::ordercomparison(std::vector<int> &vec)
{
	bool ordered = false;
	bool flag = false;
	std::vector<int>::iterator it;
	while(ordered == false)
	{
		flag = false;
		for (it=vec.begin(); it != vec.end(); it++)
		{
			if ((it + 1) != vec.end() && (*it) > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				flag = true;
			}
		}
		if (flag == true)
			ordered = false;
		else
			ordered = true;
	}
	return(true);
}
*/