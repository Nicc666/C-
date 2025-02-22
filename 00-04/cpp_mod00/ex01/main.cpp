/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:39 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:40:42 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	int	ind;
	std::string command;
	std::string temp;
	PhoneBook phonebook;

	ind = 0;
	while (1)
	{
		std::cout << "\033[32m" << "Insert command: ADD, SEARCH, EXIT" << "\033[0m" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
		{
			std::cout << "\033[33m" << "Insert index to search (range 1 - 8)" << "\033[0m" << std::endl;
			std::cin >> ind;
			if (std::cin.fail())
			{
            	std::cout << "\033[31m" << "Invalid" << "\033[0m" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::getline(std::cin, temp);
				continue;
			}
			std::getline(std::cin, temp);
			phonebook.search(ind);
		}
		else if (command == "EXIT")
			break;
		else
            std::cout << "\033[31m" << "Invalid command" << "\033[0m" << std::endl;
	}
	return(0);
}
