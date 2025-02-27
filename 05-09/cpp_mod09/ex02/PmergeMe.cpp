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
		//it++;
		it = it + 1;
	}
	std::vector<std::pair<int, int> >::iterator it_p;
	for(it_p = p.begin(); it_p != p.end(); it_p++)
	{
		if (it_p->second < it_p->first)
			std::swap(it_p->first, it_p->second);
	}
	return;
}

void PmergeMe::merge(std::vector<int> &v, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int leftArr[n1];
	int rightArr[n2];
	for (int i = 0; i < n1; i++)
		leftArr[i] = v[left + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = v[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			v[k] = leftArr[i];
			i++;
		}
		else
		{
			v[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		v[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		v[k] = rightArr[j];
		j++;
		k++;
	}
	return;
}

void PmergeMe::mergesort(std::vector<int> &v, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort(v, left, mid);
		mergesort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
	return;
}

void PmergeMe::binaryinsertion(std::vector<int> &second)
{
	std::vector<int>::iterator it;
	for (it=second.begin(); it!=second.end(); it++)
	{
		int i = 0;
		int e = this->ret.size() - 1;
		while (i <= e)
		{
			int m = i + (e - i) / 2;
			if (ret[m] == *it)
			{
				i = m;
				break;
			}
			else if (ret[m] < *it)
				i = m + 1;
			else
				e = m - 1;
		}
		ret.insert(ret.begin() + i, *it);
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
	this->mergesort(first, 0, first.size() - 1);
	std::vector<int>::iterator it;
	std::vector<int>::iterator it_r;
	for(it=first.begin(); it!=first.end(); it++)
		ret.push_back(*it);
	this->binaryinsertion(second);
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
		//it++;
		it = it + 1;
	}
	std::deque<std::pair<int, int> >::iterator it_p;
	for(it_p = p.begin(); it_p != p.end(); it_p++)
	{
		if (it_p->second < it_p->first)
			std::swap(it_p->first, it_p->second);
	}
	return;
}

void PmergeMe::merge_d(std::deque<int> &v, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int leftArr[n1];
	int rightArr[n2];
	for (int i = 0; i < n1; i++)
		leftArr[i] = v[left + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = v[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			v[k] = leftArr[i];
			i++;
		}
		else
		{
			v[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		v[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		v[k] = rightArr[j];
		j++;
		k++;
	}
	return;
}

void PmergeMe::mergesort_d(std::deque<int> &v, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort_d(v, left, mid);
		mergesort_d(v, mid + 1, right);
		merge_d(v, left, mid, right);
	}
	return;
}

void PmergeMe::binaryinsertion_d(std::deque<int> &second)
{
	std::deque<int>::iterator it;
	for (it=second.begin(); it!=second.end(); it++)
	{
		int i = 0;
		int e = this->fin.size() - 1;
		while (i <= e)
		{
			int m = i + (e - i) / 2;
			if (fin[m] == *it)
			{
				i = m;
				break;
			}
			else if (fin[m] < *it)
				i = m + 1;
			else
				e = m - 1;
		}
		fin.insert(fin.begin() + i, *it);
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
	this->binaryinsertion_d(second);
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
