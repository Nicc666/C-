#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int	main()
{
	int	ind;
	std::string command;
	PhoneBook phonebook;

	ind = 0;
	while (1)
	{
		std::cout << "Insert command: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
		{
			std::cout << "Insert index to search (range 1 - 8)" << std::endl;
			std::cin >> ind;
			if (std::cin.fail())
			{
            	std::cout << "Invalid" << std::endl;
				std::cin.clear();

				std::cin.ignore();
				
				continue;
			}
			std::cout << ind;
			phonebook.search(ind);
		}
		else if (command == "EXIT")
			break;
		else
			continue;
	}
	return(0);
}
