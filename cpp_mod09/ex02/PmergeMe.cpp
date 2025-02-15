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
		}
	}
	return (true);
}

void PmergeMe::printlist(std::vector<int> &vec)
{
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
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

bool PmergeMe::fillpair(void)
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
	return(true);
}



bool PmergeMe::orderpair(void)
{
	std::vector<std::pair<int, int> >::iterator it;
	for(it=p.begin(); it!=p.end(); it++)
	{
		if (it->second < it->first)
		{
			std::swap(it->first, it->second);
		}
	}
	return(true);
}

bool PmergeMe::vectorret(std::vector<int> &first, std::vector<int> &second)
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
	return(true);
}

bool PmergeMe::final(void)
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
	std::cout << "prima lista:" << std::endl; //test
	this->printlist(first); //test
	std::cout << "seconda lista:" << std::endl; //test
	this->printlist(second); //test
	std::sort(first.begin(), first.end());
	std::cout << "prima lista ordinata:" << std::endl; //test
	this->printlist(first); //test
	this->vectorret(first, second);
	return(true);
}

void PmergeMe::algoritm(char **argv)
{
	if (!this->fillint(argv))
		return;
	if (data.size() <= 3)
	{
		std::sort(data.begin(), data.end());
		std::cout << "RISULTATO FINALE:" << std::endl; //test
		this->printlist(data); //test
		return;
	}
	if (!this->fillpair())
		return;
	this->printlist(data); //test
	std::cout << "COPPIE:" << std::endl; //test
	this->printpair(); //test
	if (!this->orderpair())
		return;
	std::cout << "COPPIE ordinate :" << std::endl; //test
	this->printpair(); //test
	if (!this->final())
		return;
	std::cout << "RISULTATO FINALE:" << std::endl; //test
	this->printlist(ret);
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