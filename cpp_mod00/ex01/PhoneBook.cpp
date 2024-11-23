/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:48 by nspinell          #+#    #+#             */
/*   Updated: 2024/11/23 18:21:26 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
	current_index = 0;
	while (i < 8)
	{
		contact[i].setindex(i + 1);
		i++;
	}
}

PhoneBook::~PhoneBook()
{
	std::cout << "distructor called" << std::endl;
}

void	PhoneBook::add_detail(int i)
{
	std::string temp;

	while (contact[i].get_first_name() == "")
	{
		std::cout << "Insert name" << std::endl;
		std::getline(std::cin, temp);
		contact[i].set_first_name(temp);
	}
	while (contact[i].get_last_name() == "")
	{
		std::cout << "Insert last_name" << std::endl;
		std::getline(std::cin, temp);
		contact[i].set_last_name(temp);
	}
	while (contact[i].get_nickname() == "")
	{
		std::cout << "Insert nickname" << std::endl;
		std::getline(std::cin, temp);
		contact[i].set_nickname(temp);
	}
	while (contact[i].get_phone_number() == "")
	{
		std::cout << "Insert phone_number" << std::endl;
		std::getline(std::cin, temp);
		contact[i].set_phone_number(temp);
	}
	while (contact[i].get_darkest_secret() == "")
	{
		std::cout << "Insert dark_secret" << std::endl;
		std::getline(std::cin, temp);
		contact[i].set_darkest_secret(temp);
	}
	std::cout << "Contact added" << std::endl;
	return;
}

void PhoneBook::add()
{
	i=0;

	current_index++;
	if (current_index > 8)
	{
		i = (current_index - 1) % 8;
		contact[i].set_first_name("");
		contact[i].set_last_name("");
		contact[i].set_nickname("");
		contact[i].set_phone_number("");
		contact[i].set_darkest_secret("");
		add_detail(i);
	}
	else
	{
		while (i < 8)
		{
			if (contact[i].get_first_name() == "")
			{			
				add_detail(i);
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
	std::cout << std::setw(10) << contact[i].getindex() << "|"\
	<< std::setw(10) << truncate(contact[i].get_first_name()) << "|"\
	<< std::setw(10) << truncate(contact[i].get_last_name()) << "|"\
	<< std::setw(10) << truncate(contact[i].get_first_name()) << "|" << std::endl;
	return ;
}
