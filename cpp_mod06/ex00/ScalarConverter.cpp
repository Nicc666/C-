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
	for(i=i; s[i] != '\0'; i++)
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

bool pseudoliterals(std::string s)
{
	if (s == "nan" || s == "nanf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	else
		return false;
}

int verify(std::string s) //0 char, 1 int, 2 float, 3 double, 4 pseudol, 5 error
{
	if (s.length() == 1 && isdigit(s[0]) == 0)
		return (0);
	if (isinteger(s) == true)
		return(1);
	if (isfloat(s) == true)
		return(2);
	if (isdouble(s) == true)
		return(3);
	if (pseudoliterals(s) == true)
		return(4);
	return(5);
}

void printchar(std::string &s)
{
	char c;
	int x;
	float f;
	double d;

	c = s[0];
	x = static_cast<int>(s[0]);
	f = static_cast<float>(s[0]);
	d = static_cast<double>(s[0]);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
	return;
}

void printint(std::string &s)
{
	char c;
	int x;
	float f;
	double d;
	long int test;

	test = strtol(s.c_str(), NULL, 10);
	if (test > INT_MAX || test < INT_MIN)
	{
		std::cout << "Error: int overflow" << std::endl;
		return;
	}
	x = static_cast<int>(test);
	if (x < SCHAR_MIN || x > SCHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else
	{
		c = static_cast<char>(x);
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << x << std::endl;
	f = static_cast<float>(x);
	d = static_cast<double>(x);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

void printfloat(std::string &s)
{
	char c;
	int x;
	float f;
	double d;
	bool over;

	f = strtof(s.c_str(), NULL);
	if (f > INT_MAX || f < INT_MIN)
		over = true;
	else
	{
		x = static_cast<int>(f);
		over = false;
	}
	if (over == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (x < SCHAR_MIN || x > SCHAR_MAX)
			std::cout << "char: impossible" << std::endl;
		else
		{
			c = static_cast<char>(x);
			if (std::isprint(c))
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << x << std::endl;
	}
	d = static_cast<double>(f);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

void printdouble(std::string &s)
{
	char c;
	int x;
	float f;
	double d;
	bool over;

	d = strtod(s.c_str(), NULL);
	if (d > INT_MAX || d < INT_MIN)
		over = true;
	else
	{
		x = static_cast<int>(d);
		over = false;
	}
	if (over == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (x < SCHAR_MIN || x > SCHAR_MAX)
			std::cout << "char: impossible" << std::endl;
		else
		{
			c = static_cast<char>(x);
			if (std::isprint(c))
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << x << std::endl;
	}
	f = static_cast<float>(d);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return;
}

void ScalarConverter::convert(std::string s)
{
	int ret = 5;

	ret = verify(s);
	if (ret == 0)
		return(printchar(s));
	else if (ret == 1)
		return(printint(s));
	else if (ret == 2)
		return(printfloat(s));
	else if (ret == 3)
		return(printdouble(s));
	else if (ret == 4)
		return;
	else
		std::cout << "Error: invalid input" << std::endl;
	return;
}
