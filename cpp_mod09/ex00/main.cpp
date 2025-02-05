/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:44:32 by nspinell          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:54 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	(void)argv;
	BitcoinExchange bit;
	bit.fillmap("data.csv");
	//bit.printmap();
	bit.search(argv[1]);
/*
	std::string s;
	while (std::getline(input, s))
	{
		std::cout << s << std::endl;;
	}
	if (input.eof() == true)
		return 0;
	std::ifstream in;
	in.open("data.csv", std::ifstream::in);
	if (in.is_open() == false)
	{
		std::cout << "Open file error" << std::endl;
		return 1;
	}*/
	return 0;
}
