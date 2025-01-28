/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/17 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "test_with_std_list................" << std::endl;
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);
	std::list<int>::iterator itA = l.begin();
	std::list<int>::iterator itE = l.end();
	++itA;
	--itA;
	while (itA != itE)
	{
	std::cout << *itA << std::endl;
	++itA;
	}
	std::list<int> l2(l);
	std::cout << "test_double................" << std::endl;
	MutantStack<double> dio;
	dio.push(23.67);
	for (int i = 0; i < 176; i++)
	{
		dio.push(1.99 + i*10);
	}
	MutantStack<double>::iterator iniz = dio.begin();
	MutantStack<double>::iterator fin = dio.end();
	for (; iniz != fin; iniz++)
	{
		std::cout << *iniz << std::endl;
	}
	std::cout << "copy costructor test................" << std::endl;
	MutantStack<double> dio2(dio);
	MutantStack<double>::iterator copy = dio2.begin();
	MutantStack<double>::iterator copy2 = dio2.end();
	for (; copy != copy2; copy++)
	{
		std::cout << *copy << std::endl;
	}
	return 0;
}
