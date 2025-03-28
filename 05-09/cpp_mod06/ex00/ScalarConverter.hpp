/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/05 17:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		~ScalarConverter(void);
		static void convert(std::string s);
};

int verify(std::string s);
bool isinteger(std::string s);
bool isfloat(std::string s);
bool isdouble(std::string s);
bool pseudoliterals(std::string s);
void printchar(std::string &s);
void printint(std::string &s);
void printfloat(std::string &s);
void printdouble(std::string &s);

#endif