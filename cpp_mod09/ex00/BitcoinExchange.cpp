/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return(*this);
	return(*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

int BitcoinExchange::fillmap(const char *file)
{
	std::ifstream input(file);
	if (input.is_open() == false)
	{
		std::cout << "Open file error" << std::endl;
		return (1);
	}
	std::string s;
	size_t r;
	if (input.eof() == true)
		return(0);
	std::getline(input, s);
	if (s != "date,exchange_rate")
	{
		std::cout << "first line Error" << std::endl;
		return(1);
	}
	//std::cout << s << std::endl;
	while (std::getline(input, s))
	{
		r = s.find(",");
		if (r != 10)
		{
			std::cout << "Error format" << std::endl;
			return(1);
		}
		std::string num = s.substr((r + 1), s.size());
		this->data.insert(std::pair<std::string, double>(s.substr(0, r), strtod(num.c_str(), NULL)));
		//std::cout << s << std::endl;
	}
	return(0);
}

void BitcoinExchange::printmap(void)
{
	std::map<std::string,double>::iterator it;
	for (it = this->data.begin(); it != this->data.end(); it++)
	{
		std::cout << "data: " << it->first << "num: " << it->second << std::endl;
	}
}

void BitcoinExchange::searchdatabase(std::string d, double num)
{
	std::map<std::string,double>::iterator it;
	for (it = this->data.begin(); it != this->data.end(); it++)
	{
		if (it->first == d)
		{
			std::cout << (it->first) << " => " << num << " = ";
			std::cout << (it->second * num) << std::endl;
			return;
		}
		else if (it->first > d)
		{
			it--;
			std::cout << (it->first) << " => " << num << " = ";
			std::cout << (it->second * num) << std::endl;
			return;
		}
		//std::cout << "data: " << it->first << "num: " << it->second << std::endl;
	}
}

int BitcoinExchange::search(char *file)
{
	std::ifstream input(file);
	if (input.is_open() == false)
	{
		std::cout << "Open input file error" << std::endl;
		return (1);
	}
	std::string s;
	size_t r;
	if (input.eof() == true)
		return(0);
	std::getline(input, s);
	if (s != "date | value")
	{
		std::cout << "first line Error in input file" << std::endl;
		return(1);
	}
	//std::cout << s << std::endl;
	while (std::getline(input, s))
	{
		r = s.find("|");
		if (r != 11)
		{
			std::cout << "Error: bad input" << std::endl;
			continue;
		}
		std::string dat = (s.substr(0, r - 1));
		double d = (strtod((s.substr(r + 2, s.size())).c_str(), NULL));
		if (!this->controlinput(dat, d))
			continue;
		this->searchdatabase(dat, d);
	}
	return(0);
}

bool BitcoinExchange::controlinput(std::string dat, double d)
{
	if (d < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return(false);
	}
	if (d > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return(false);
	}
	if (dat.size()>10)
		return(false);
	return(true);
}
