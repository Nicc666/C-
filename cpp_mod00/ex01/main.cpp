#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int	main()
{
	std::string command;
	PhoneBook phonebook;

	std::cout << "Inserire comando, comandi accettati: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			continue;
		else if (command == "EXIT")
			break;
		else
			continue;
	}
	return(0);
}
