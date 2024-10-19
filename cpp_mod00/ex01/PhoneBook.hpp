/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspinell <nspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:40:59 by nspinell          #+#    #+#             */
/*   Updated: 2024/10/19 15:41:01 by nspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public :
	Contact contact[8];
	int i;
	int current_index;

	PhoneBook ();
	~PhoneBook ();

	void add();
	std::string truncate(std::string s);
	void search(int j);
};

#endif