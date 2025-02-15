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

//class costructor e destructor

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
	this->ret = other.ret;
	this->d = other.d;
	this->fin = other.fin;
	return(*this);
}

PmergeMe::~PmergeMe(void)
{
}

//input check

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
			if ((argv[i][j] == '+' || argv[i][j] == '-') && j == 0 && argv[i][j + 1] == '\0')
				return (false);
		}
	}
	return (true);
}

//vector

void PmergeMe::printvector(std::vector<int> &vec)
{
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return;
}

bool PmergeMe::fillvector(char **argv)
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

void PmergeMe::fill_order_pair(std::vector<std::pair<int, int> > &p)
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
	std::vector<std::pair<int, int> >::iterator it_p;
	for(it_p = p.begin(); it_p != p.end(); it_p++)
	{
		if (it_p->second < it_p->first)
			std::swap(it_p->first, it_p->second);
	}
	return;
}

void PmergeMe::algorithm(std::vector<std::pair<int, int> > &p)
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<std::pair<int, int> >::iterator it_p;
	for(it_p=p.begin(); it_p!=p.end(); it_p++)
	{
		first.push_back(it_p->first);
		second.push_back(it_p->second);
	}
	if (data.size() % 2 != 0)
		first.push_back(data.back());
	std::sort(first.begin(), first.end());
	std::vector<int>::iterator it;
	std::vector<int>::iterator it_r;
	for(it=first.begin(); it!=first.end(); it++)
		ret.push_back(*it);
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

void PmergeMe::sortvector(void)
{
	clock_t start = clock();
	std::cout << "Before: ";
	this->printvector(data);
	if (data.size() <= 3)
	{
		std::sort(data.begin(), data.end());
		std::cout << "After:  ";
		this->printvector(data);
		clock_t end = clock();
		double elapsed = double(end - start) / CLOCKS_PER_SEC;
    	std::cout << "Time to process a range of " << data.size() << " elements with std::vector: " << elapsed*1000000.0 << " us" << std::endl;
		return;
	}
	std::vector<std::pair<int, int> > p;
	this->fill_order_pair(p);
	this->algorithm(p);
	clock_t end = clock();
	std::cout << "After:  ";
	this->printvector(ret);
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << data.size() << " elements with std::vector: " << elapsed*1000000.0 << " us" << std::endl;
	return;
}

//deque

void PmergeMe::printdeque(std::deque<int> &deq)
{
	std::deque<int>::iterator it;
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return;
}

bool PmergeMe::filldeque(char **argv)
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
		d.push_back(x);
	}
	return(true);
}

void PmergeMe::fill_order_pair_d(std::deque<std::pair<int, int> > &p)
{
	std::deque<int>::iterator it;
	for(it=d.begin(); it!=d.end(); it++)
	{
		if ((it+1) == d.end())
			break;
		p.push_back(std::make_pair(*it, *(it + 1)));
		it++;
	}
	std::deque<std::pair<int, int> >::iterator it_p;
	for(it_p = p.begin(); it_p != p.end(); it_p++)
	{
		if (it_p->second < it_p->first)
			std::swap(it_p->first, it_p->second);
	}
	return;
}

void PmergeMe::algorithm_d(std::deque<std::pair<int, int> > &p)
{
	std::deque<int> first;
	std::deque<int> second;
	std::deque<std::pair<int, int> >::iterator it_p;
	for(it_p=p.begin(); it_p!=p.end(); it_p++)
	{
		first.push_back(it_p->first);
		second.push_back(it_p->second);
	}
	if (d.size() % 2 != 0)
		first.push_back(d.back());
	std::sort(first.begin(), first.end());
	std::deque<int>::iterator it;
	std::deque<int>::iterator it_r;
	for(it=first.begin(); it!=first.end(); it++)
		fin.push_back(*it);
	for(it=second.begin(); it!=second.end(); it++)
	{
		for(it_r = fin.begin(); it_r != fin.end(); it_r++)
		{
			if ((it_r + 1) != fin.end() && *it <= *(it_r + 1))
			{
				fin.insert(it_r+1, *it);
				break;
			}
			else if ((it_r + 1) == fin.end())
			{
				fin.push_back(*it);
				break;
			}
		}
	}
	return;
}

void PmergeMe::sortdeque(void)
{
	clock_t start = clock();
	std::cout << "Before: ";
	this->printdeque(d);
	if (d.size() <= 3)
	{
		std::sort(d.begin(), d.end());
		std::cout << "After:  ";
		this->printdeque(d);
		clock_t end = clock();
		double elapsed = double(end - start) / CLOCKS_PER_SEC;
    	std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << elapsed*1000000.0 << " us" << std::endl;
		return;
	}
	std::deque<std::pair<int, int> > p;
	this->fill_order_pair_d(p);
	this->algorithm_d(p);
	clock_t end = clock();
	std::cout << "After:  ";
	this->printdeque(fin);
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << elapsed*1000000.0 << " us" << std::endl;
	return;
}

//main

bool PmergeMe::sort(char **argv)
{
	if (!this->fillvector(argv))
		return(false);
	this->sortvector();
	if (!this->filldeque(argv))
		return(false);
	this->sortdeque();
	return(true);
}

/*
void PmergeMe::printpair(void)
{
	std::vector<std::pair<int, int> >::iterator it;
	it = p.begin();
	for (; it != p.end(); it++)
		std::cout << "first " << it->first << " second " << it->second << std::endl;
	return;
}

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