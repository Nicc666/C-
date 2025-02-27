/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return(*this);
	this->data = other.data;
	return(*this);
}

RPN::~RPN(void)
{
}

void RPN::printlist(void)
{
	std::list<int>::iterator it;
	it = data.begin();
	for (; it != data.end(); it++)
		std::cout << *it << std::endl;
	return;
}

bool RPN::inputerror(std::string s)
{
	std::string::iterator it;
	it = s.begin();
	for (; it != s.end(); it++)
	{
		if ((isdigit(*it) == false) && (*it != ' ') && (*it != '+') && (*it != '-') && (*it != '*') && (*it != '/'))
			return (false);
	}
	return (true);
}

bool RPN::isnumber(std::string s)
{
	size_t i = 0;
	if (s.size() == 1 && (s[0] == '+' || s[0] == '-'))
		return(false);
	if (s[0] == '+' || s[0] == '-')
		i++;
	for(; i < s.size(); i++)
	{
		if (isdigit(s[i]) == false)
			return(false);
	}
	return(true);
}

void RPN::rpn(std::string s)
{
	long int i;
	std::istringstream ss(s);
	std::string str;
	while (ss >> str)
	{
		if (str.size() > 0 && this->isnumber(str) == true)
		{
			i = strtol(str.c_str(), NULL, 10);
			if (i > INT_MAX || i < INT_MIN)
				throw RPN::invalidexpression();
			data.push_back(i);
		}
		else if (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'))
		{
			if (this->operation(str[0]) == false)
				throw RPN::invalidexpression();
		}
		else
			throw RPN::invalidexpression();
	}
	if (data.size() != 1)
		throw RPN::invalidexpression();
	else
	{
		std::cout << data.back() << std::endl;
		return;
	}
}

bool RPN::operation(char c)
{
	if (data.size() < 2)
		return(false);
	char oper[] = {'+', '-', '*', '/'};
	int (RPN::*operpointer[4])(int x, int y);
	operpointer[0] = &RPN::add;
	operpointer[1] = &RPN::minus;
	operpointer[2] = &RPN::moltiplication;
	operpointer[3] = &RPN::divide;
	int r;
	std::list<int>::iterator x = --(--data.end());
	std::list<int>::iterator y = --data.end();
	for (int i = 0; i < 4; i++)
	{
		if (c == oper[i])
		{
			if (i == 3 && *y == 0)
			{
				std::cout << "Error: division for 0" << std::endl;
				return(false);
			}
			r = (this->*operpointer[i])(*x, *y);
			data.pop_back();
			data.pop_back();
			data.push_back(r);
			return(true);
		}
	}
	return(false);
}

int RPN::add(int x, int y)
{
	return(x + y);
}

int RPN::minus(int x, int y)
{
	return(x - y);
}

int RPN::moltiplication(int x, int y)
{
	return(x * y);
}

int RPN::divide(int x, int y)
{
	if (y == 0)
		return(-2147483648);
	return(x / y);
}
