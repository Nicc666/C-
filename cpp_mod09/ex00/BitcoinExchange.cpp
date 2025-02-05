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

bool BitcoinExchange::fillmap(const char *file)
{
	std::string s;
	size_t r;
	std::ifstream input(file);
	if (input.is_open() == false)
	{
		std::cout << "Error: Open database file error" << std::endl;
		return (false);
	}
	std::getline(input, s);
	if (input.eof() == true)
	{
		std::cout << "Error: Empty databse" << std::endl;
		return (false);
	}
	if (s != "date,exchange_rate")
	{
		std::cout << "Error in first line Database must be: date,exchange_rate" << std::endl;
		return(false);
	}
	while (std::getline(input, s))
	{
		r = s.find(",");
		if (r != 10)
		{
			std::cout << "Error format" << std::endl;
			return(false);
		}
		std::string num = s.substr((r + 1), s.size());
		this->data.insert(std::pair<std::string, double>(s.substr(0, r), strtod(num.c_str(), NULL)));
	}
	return(true);
}

void BitcoinExchange::printmap(void)
{
	std::map<std::string,double>::iterator it;
	for (it = this->data.begin(); it != this->data.end(); it++)
		std::cout << "data: " << it->first << "num: " << it->second << std::endl;
	return;
}

bool BitcoinExchange::btcsearch(char *file)
{
	std::string s;
	size_t r;
	std::ifstream input(file);
	if (input.is_open() == false)
	{
		std::cout << "Error: Open input file error" << std::endl;
		return (false);
	}
	std::getline(input, s);
	if (input.eof() == true)
	{
		std::cout << "Error: Empty input file" << std::endl;
		return (false);
	}
	if (s != "date | value")
	{
		std::cout << "Error: first line must be: date | value" << std::endl;
		return(false);
	}
	while (std::getline(input, s))
	{
		r = s.find("|");
		if (r != 11)
		{
			std::cout << "Error: bad input" << " => " << s << std::endl;
			continue;
		}
		std::string dat = (s.substr(0, r - 1));
		std::string num = (s.substr(r + 2, s.size()));
		if (!isdouble(num))
		{
			std::cout << "Error: bad input" << " => " << s << std::endl;
			continue;
		}
		double d = (strtod(num.c_str(), NULL));
		if (!this->controlinput(dat, d))
			continue;
		this->searchdatabase(dat, d);
	}
	return(true);
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
			if (it == this->data.begin())
			{
				std::cout << (it->first) << " => " << "No data found" << std::endl;
				return;
			}
			it--;
			std::cout << (it->first) << " => " << num << " = ";
			std::cout << (it->second * num) << std::endl;
			return;
		}
	}
	if (it == this->data.end())
	{
		it--;
		std::cout << (it->first) << " => " << num << " = ";
		std::cout << (it->second * num) << std::endl;
	}
	return;
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
	if (!checkdate(dat))
	{
		std::cout << "Error: bad date format." << std::endl;
		return(false);
	}
	return(true);
}

bool BitcoinExchange::checkdate(std::string dat)
{
	int year, month, day;
    char c1, c2;
	if (dat.size() != 10 || dat[4] != '-' || dat[7] != '-')
		return false;
    std::istringstream ss(dat);
    ss >> year >> c1 >> month >> c2 >> day;
    if (ss.fail() || c1 != '-' || c2 != '-')
		return false;
    if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
    if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		return false;
	return(true);
}

bool BitcoinExchange::isdouble(std::string s)
{
	int i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (isdigit(s[i]) == 0)
		return(false);
	while (s[i] != '.' && s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(false);
		i++;
	}
	if (s[i] == '.')
		i++;
	else if (s[i] == '\0')
		return(true);
	if (s[i] == '\0')
		return(false);
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(false);
		i++;
	}
	if (s[i] == '\0')
		return(true);
	else
		return(false);
}
