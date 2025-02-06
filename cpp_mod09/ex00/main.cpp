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
	{
		std::cout << "Error: arg numbers" << std::endl;
		return(1);
	}
	BitcoinExchange bit;
	if (!bit.fillmap("empty.csv"))
	{
		std::cout << "Error: provide good database" << std::endl;
		return(1);
	}
	//bit.printmap();
	if (!bit.btcsearch(argv[1]))
		return(1);
	return 0;
}
