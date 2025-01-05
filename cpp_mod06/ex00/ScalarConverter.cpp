/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool isinteger(std::string s)
{
	int i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	for(i=0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
		{
			return(0);
		}
	}
	return(1);
}

bool isfloat(std::string s)
{
	int i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (isdigit(s[i]) == 0)
		return(0);
	while (s[i] != '.' && s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	if (s[i] == '.')
		i++;
	else if (s[i] == '\0')
		return(0);
	if (s[i] == '\0' || s[i] == 'f')
		return(0);
	while (s[i] != 'f' && s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	if (s[i] == 'f')
		i++;
	else if (s[i] == '\0')
		return(0);
	if (s[i] == '\0')
		return(1);
	else
		return(0);
}

bool isdouble(std::string s)
{
	int i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (isdigit(s[i]) == 0)
		return(0);
	while (s[i] != '.' && s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	if (s[i] == '.')
		i++;
	else if (s[i] == '\0')
		return(0);
	if (s[i] == '\0')
		return(0);
	while (s[i] != '\0')
	{
		if (isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	if (s[i] == '\0')
		return(1);
	else
		return(0);
}

int verify(std::string s) //0 char, 1 int, 2 float, 3 double, 5 error
{
	if (s.length() == 1 && isdigit(s[0]) == 0)
		return (0);
	if (isinteger(s) == true)
		return(1);
	if (isfloat(s) == true)
		return(2);
	if (isdouble(s) == true)
		return(3);
	return(5);
}

void ScalarConverter::convert(std::string s)
{
	unsigned char c;
	int x;
	float f;
	double d;
	int ret = 5;
	std::stringstream ss(s);

	ret = verify(s);

	std::cout << "ret: " << ret << std::endl; //test

	if (ret == 0)
	{
		ss >> c;
		//c = s[0];
		x = static_cast<int>(s[0]);
		f = static_cast<float>(s[0]);
		d = static_cast<double>(s[0]);
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << x << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (ret == 1)
	{
		ss >> x;
		//x = std::stoi(s);
		c = static_cast<char>(x);
		f = static_cast<float>(x);
		d = static_cast<double>(x);
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << x << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (ret == 2)
	{
		ss >> f;
		//f = std::stof(s);
		x = static_cast<int>(f);
		c = static_cast<char>(x);
		d = static_cast<double>(f);
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << x << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (ret == 3)
	{
		ss >> d;
		//d = std::stod(s);
		x = static_cast<int>(d);
		c = static_cast<char>(x);
		f = static_cast<float>(d);
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << x << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	else if (ret == 5)
	{
		std::cout << "Error: invalid input" << std::endl;
		return;
	}
	return;
}
