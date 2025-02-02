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
	std::cout << s << std::endl;
	while (std::getline(input, s))
	{
		r = s.find(",");
		if (r != 11)
		{
			std::cout << "Error format" << std::endl;
			return(1);
		}
		std::string num = s.substr(11, s.size());
		this->data.insert(std::pair<std::string, double>(s.substr(0, 10), strtod(num.c_str(), NULL)));
		//BitcoinExchange::checkline(s.c_str());
		std::cout << s << std::endl;
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
