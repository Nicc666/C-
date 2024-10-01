#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook ()
{
	i = 0;
	current_index = 0;
	while (i < 8)
	{
		contact[i].index = i + 1;
		i++;
	}
}

void PhoneBook::add()
{
	i=0;

	current_index++;
	if (current_index > 8)
	{
		i = (current_index - 1) % 8;
		contact[i].name = "";
		contact[i].surname = "";
		contact[i].nickname = "";
		contact[i].phone_number = "";
		contact[i].secret = "";
		while (contact[i].name == "")
			{
				std::cout << "Insert name" << std::endl;
				std::getline(std::cin, contact[i].name);
			}
			while (contact[i].surname == "")
			{
				std::cout << "Insert surname" << std::endl;
				std::getline(std::cin, contact[i].surname);
			}
			while (contact[i].nickname == "")
			{
				std::cout << "Insert nickname" << std::endl;
				std::getline(std::cin, contact[i].nickname);
			}
			while (contact[i].phone_number == "")
			{
				std::cout << "Insert phone_number" << std::endl;
				std::getline(std::cin, contact[i].phone_number);
			}
			while (contact[i].secret == "")
			{
				std::cout << "Insert dark_secret" << std::endl;
				std::getline(std::cin, contact[i].secret);
			}
			std::cout << "Contact added" << std::endl;
	}
	else
	{
		while (i < 8)
		{
			if (contact[i].name == "")
			{			
				while (contact[i].name == "")
				{
					std::cout << "Insert name" << std::endl;
					std::getline(std::cin, contact[i].name);
				}
				while (contact[i].surname == "")
				{
					std::cout << "Insert surname" << std::endl;
					std::getline(std::cin, contact[i].surname);
				}
				while (contact[i].nickname == "")
				{
					std::cout << "Insert nickname" << std::endl;
					std::getline(std::cin, contact[i].nickname);
				}
				while (contact[i].phone_number == "")
				{
					std::cout << "Insert phone_number" << std::endl;
					std::getline(std::cin, contact[i].phone_number);
				}
				while (contact[i].secret == "")
				{
					std::cout << "Insert dark_secret" << std::endl;
					std::getline(std::cin, contact[i].secret);
				}
				std::cout << "Contact added" << std::endl;
				break;
			}
			i++;
		}
	}
	return ;
}

std::string PhoneBook::truncate(std::string s)
{
	std::string p;
	if (s.length() > 10)
	{
		p = s.substr(0, 9) + ".";
		return(p);
	}
	else
		return(s);
}

void PhoneBook::search(int j)
{
	i=0;

	if (j < 1 || j > 8)
	{
		std::cout << "Insert a valid index" << std::endl;
		return ;
	}
	while (i + 1 != j)
		i++;
	std::cout << std::setw(10) << "Index" << "|"\
     << std::setw(10) << "First Name" << "|"\
    << std::setw(10) << "Last Name" << "|"\
    << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::setw(10) << contact[i].index << "|"\
	<< std::setw(10) << truncate(contact[i].name) << "|"\
	<< std::setw(10) << truncate(contact[i].surname) << "|"\
	<< std::setw(10) << truncate(contact[i].nickname) << "|" << std::endl;
	return ;
}
